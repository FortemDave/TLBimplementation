#ifndef BLOCKFORMAT_H
#define BLOCKFORMAT_H

// Used for Logic Decisions
#define INVALID_BLOCK __UINT64_MAX__
#define UNUSED_BLOCK  __UINT64_MAX__
typedef long long t_integer;

class c_Block
{
private:
    t_integer m_FrameNumber;
    t_integer m_PageNumber;
    t_integer m_lastAccessed;
    bool m_validBlock;

public:
    void f_initBlock(t_integer m_inputPageNumber, t_integer m_inputFrameNumber, t_integer m_inputLastAccessed);

    void f_setBlockFrameNumber(t_integer m_inputFrameNumber);
    void f_setBlockPageNumber(t_integer m_inputPageNumber);
    void f_setBlockLastAccessed(t_integer m_inputLastAccessed);
    void f_setBlockValidity(bool m_inputValidBlock);

    t_integer f_getBlockFrameNumber();
    t_integer f_getBlockPageNumber();
    t_integer f_getBlockLastAccessed();
    t_integer f_getBlockValidity();

    c_Block f_createBlockClone();
};


#endif