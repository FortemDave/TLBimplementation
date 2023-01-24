#ifndef PAGETABLEFORMAT_H
#define PAGETABLEFORMAT_H

#include<vector>
#include<iostream>
#include<stdint.h>
#include<stdlib.h>
#include"configuration_s.hpp"
// #include"Hexadecimal_s.hpp" We'll use an in-built func or an alternative

#define PAGE_FAULT __UINT64_MAX__
typedef long long t_integer;

struct s_pageTableEntry
{
    t_integer m_PTEFrameNumber;
    t_integer m_PTEPageNumber;
    bool m_isPresent;
    bool m_isProtected;
    bool m_isDirty;

    s_pageTableEntry(){};

    s_pageTableEntry(t_integer m_pageNumber, t_integer m_frameNumber):
    m_PTEPageNumber(m_pageNumber),m_PTEFrameNumber(m_frameNumber),m_isPresent(true),m_isProtected(false),m_isDirty(false){}
};

class c_PageTable
{
private:
    std::vector<s_pageTableEntry> m_pageTable;

public:
    c_PageTable(){};
    ~c_PageTable(){};
    void f_makePTE(t_integer m_inputPageNumber, t_integer m_inputFrameNumber);
    t_integer f_getPTEframeNumber(t_integer m_inputPageNumber);

};

#endif