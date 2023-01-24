#include "BlockStruct.hpp"

void c_Block::f_initBlock(t_integer m_inputPageNumber, t_integer m_inputFrameNumber, t_integer m_inputLastAccessed){
    m_FrameNumber   = m_inputFrameNumber;
    m_PageNumber    = m_inputPageNumber;
    m_lastAccessed  = m_inputLastAccessed;
    m_validBlock    = true;
}

void c_Block::f_setBlockFrameNumber(t_integer m_inputFrameNumber){m_FrameNumber = m_inputFrameNumber;}
void c_Block::f_setBlockPageNumber(t_integer m_inputPageNumber){m_PageNumber = m_inputPageNumber;}
void c_Block::f_setBlockLastAccessed(t_integer m_inputLastAccessed){m_lastAccessed  = m_inputLastAccessed;}
void c_Block::f_setBlockValidity(bool m_inputValidBlock){m_validBlock = m_inputValidBlock;}

t_integer c_Block::f_getBlockFrameNumber(){return m_FrameNumber;}
t_integer c_Block::f_getBlockPageNumber(){return m_PageNumber;}
t_integer c_Block::f_getBlockLastAccessed(){return m_lastAccessed;}
t_integer c_Block::f_getBlockValidity(){return m_validBlock;}

c_Block c_Block::f_createBlockClone()
{
    c_Block m_clonedBlock;
    m_clonedBlock.f_initBlock(m_PageNumber,m_FrameNumber,m_lastAccessed);
    return m_clonedBlock;
}