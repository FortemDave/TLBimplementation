#include "PageTableStruct.hpp"

void c_PageTable::f_makePTE(t_integer m_inputPageNumber, t_integer m_inputFrameNumber){
    s_pageTableEntry m_PTEinstance(m_inputPageNumber,m_inputFrameNumber);
    m_pageTable.push_back(m_PTEinstance);
}

t_integer c_PageTable::f_getPTEframeNumber(t_integer m_inputPageNumber){ // O(n)
    for(auto m_PTEntry : m_pageTable){
        if(m_PTEntry.m_PTEPageNumber == m_inputPageNumber){
            return m_PTEntry.m_PTEFrameNumber;
        }}
    return PAGE_FAULT;    
}