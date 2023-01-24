#ifndef TRANSLATIONLOOKASIDEBUFFERSTRUCT_H
#define TRANSLATIONLOOKASIDEBUFFERSTRUCT_H

#include "PageTableSetStruct.hpp"
class c_TLB
{
private:
    c_AssociativeSet **m_sets;
    t_integer m_setCount;

public:
    c_TLB(t_integer m_TLBsize, t_integer m_inputAssociativity);
    t_integer f_getAssociativeSetIndex(t_integer m_inputPageNumber);
    t_integer f_getTLBFrameNumber(t_integer m_inputPageNumber);
    c_Block f_TLBinsertBlock(t_integer m_inputPageNumber, t_integer m_inputFrameNumber);
    c_Block f_TLBdeleteBlock(t_integer m_inputPageNumber);
};

#endif