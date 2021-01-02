#include "Pair.h"

ostream& operator<<(ostream& os, const Pair& p)
{
    os << "Pair ascii key: " << p.key << " ,char: " << (char)p.key << " ,frequency: " << p.frequency << endl;
    return os;
}
