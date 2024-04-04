#ifndef DYNMEMEX_H
#define DYNMEMEX_H

#pragma once

class DynMemEx
{
private:
    char *label;
    void freeData();

public:
    // Ctors
    DynMemEx();

    DynMemEx(const char *src);

    // Getter
    const char *getLabel() const;
    ~DynMemEx();
};

#endif