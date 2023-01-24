#include "TLBStruct.hpp"

c_TLB::c_TLB(t_integer m_TLBsize, t_integer m_inputAssociativity){
    m_setCount = m_TLBsize / m_inputAssociativity;
    m_sets = new c_AssociativeSet *[m_setCount];

    for(uint i{}; i< m_setCount; i++){
        m_sets[i] = new c_AssociativeSet(m_setCount);
    }
}
c_TLB::~c_TLB(){
    for(uint i{}; i< m_setCount; i++){
        delete m_sets[i];
    }
    delete[] m_sets;
}

t_integer c_TLB::f_getAssociativeSetIndex(t_integer m_inputPageNumber){
    return m_inputPageNumber % m_setCount;
}

t_integer c_TLB::f_getTLBFrameNumber(t_integer m_inputPageNumber){
    t_integer m_TLBindex = f_getAssociativeSetIndex(m_inputPageNumber);
    return m_sets[m_TLBindex]->f_getAssociativeSetFrameNumber(m_inputPageNumber);
}

c_Block c_TLB::f_TLBinsertBlock(t_integer m_inputPageNumber, t_integer m_inputFrameNumber){
    t_integer m_TLBindex = f_getAssociativeSetIndex(m_inputPageNumber);
    return m_sets[m_TLBindex]->f_insertBlock(m_inputPageNumber,m_inputFrameNumber);
}

c_Block c_TLB::f_TLBdeleteBlock(t_integer m_inputPageNumber){
    t_integer m_TLBindex = f_getAssociativeSetIndex(m_inputPageNumber);
    return m_sets[m_TLBindex]->f_deleteBlock(m_inputPageNumber);
}