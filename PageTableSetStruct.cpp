#include "PageTableSetStruct.hpp"
#include <stdint.h>

c_AssociativeSet::c_AssociativeSet(uint m_inputAssociativity){
    m_associativity = m_inputAssociativity;
    m_allocatedBlocks = 0;
    m_blocks = new c_Block *[m_associativity];

    for(uint i{};i<m_associativity;i++){
        m_blocks[i] = new c_Block();
    } 
}

t_integer c_AssociativeSet::f_getAssociativeSetFrameNumber(t_integer m_inputPageNumber){
    c_Block *m_blockInstance = nullptr;

    for(uint i{}; i< m_associativity; i++){
        if(m_blocks[i]->f_isValid() && 
           m_blocks[i]->f_getBlockPageNumber() == m_inputPageNumber){
            
            m_blockInstance = m_blocks[i];
            break;
        }
    }
    if(m_blockInstance /*Exists*/){
        m_blockInstance->f_setBlockLastAccessed(timer_s.curr_time());
        return m_blockInstance->f_getBlockFrameNumber();
    }
    else /*if the block instance does not exist*/{
        return BLOCK_NOT_FOUND;
    }
    
}

c_Block c_AssociativeSet::f_insertBlock(t_integer m_inputPageNumber, t_integer m_inputFrameNumber){

    c_Block m_evictedBlock;
    m_evictedBlock.f_setBlockLastAccessed(UNUSED_BLOCK);

    if(m_allocatedBlocks < m_associativity /*Empty space exists*/){
        for(uint i{}; i<m_associativity; i++){
            if(!m_blocks[i]->f_isValid()){
                m_blocks[i]->f_initBlock(m_inputPageNumber,m_inputFrameNumber,timer_s.curr_time());
                m_allocatedBlocks++;
            }
        } 
    }
    else{
        //Replacement Logic Overwrites the pre-existing block
        c_Block *m_tempBlock= f_replacementLogic();
        m_evictedBlock = m_tempBlock->f_createBlockClone();
        m_tempBlock->f_initBlock(m_inputPageNumber,m_inputFrameNumber,timer_s.curr_time());
    }
    return m_evictedBlock;
}

c_Block c_AssociativeSet::f_deleteBlock(t_integer m_inputPageNumber){
    c_Block m_evictedBlock;
    m_evictedBlock.f_setBlockLastAccessed(BLOCK_NOT_FOUND);

    for(uint i{}; i<m_associativity; i++){
        if(m_blocks[i]->f_isValid() &&
         m_blocks[i]->f_getBlockPageNumber() == m_inputPageNumber){
            m_evictedBlock = m_blocks[i]->f_createBlockClone();
            m_blocks[i]->f_setBlockValidity(false);
            m_allocatedBlocks--;

            break;
         }
    }
    return m_evictedBlock;
}

c_AssociativeSet::~c_AssociativeSet(){
    for(uint i{}; i<m_associativity; i++){
        delete m_blocks[i];
    }
    delete[] m_blocks;
}

c_Block *c_AssociativeSet::f_replacementLogic(){
    // Currently uses LRU
    c_Block *m_evictedBlock = nullptr;
    uint64_t m_oldestAccessed = UINT64_MAX;

    for(uint i{}; i< m_associativity; i++){
        if(m_blocks[i]->f_getBlockLastAccessed() < m_oldestAccessed){
            m_oldestAccessed = m_blocks[i]->f_getBlockLastAccessed();
            m_evictedBlock = m_blocks[i];
        }
    }
    return m_evictedBlock;
}