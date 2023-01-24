#ifndef PAGETABLESET_H
#define PAGETABLESET_H

#include "BlockStruct.cpp"
#include "Timer_s.hpp"
#define BLOCK_NOT_FOUND __UINT64_MAX__
typedef unsigned int uint;

class c_AssociativeSet
{
private:
    c_Block **m_blocks;
    c_Block *f_replacementLogic();

	uint m_associativity;
    uint m_allocatedBlocks; //What does it do
	
    Timer_s<long long> timer_s;
	
public:
    c_AssociativeSet(uint m_inputAssociativity);
    t_integer f_getAssociativeSetFrameNumber(t_integer m_inputPageNumber);
    c_Block f_insertBlock(t_integer m_inputPageNumber, t_integer m_inputFrameNumber);
    c_Block f_deleteBlock(t_integer m_inputPageNumber);
};

#endif