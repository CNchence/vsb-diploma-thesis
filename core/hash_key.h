#ifndef VSB_SEMESTRAL_PROJECT_HASHKEY_H
#define VSB_SEMESTRAL_PROJECT_HASHKEY_H

#include <ostream>
#include <opencv2/core/hal/interface.h>

/**
 * struct HashKey
 *
 * Custom hash key used to quickly identify valid candidates for each Window.
 * There can be max 12800 different hash keys, consisting of (d1, d2, n1, n2, n3) where:
 *   - d1, d2 are depth relative depths (p1 - c, p2 - c)
 *   - n1, n2, n3 are quantized surface normals (into 8 bins) at (p1, p2, c)
 * this gives 5 * 5 * 8 * 8 * 8 = 12800 possible different keys, where each key contains
 * list of templates corresponding to discretizied values of hash key.
 */
struct HashKey {
public:
    uchar d1, d2; // d1, d2 relative depths are quantization into 5 bins each [index 0 - 4]
    uchar n1, n2, n3; // n1, n2, n3 surface normals are quantized into 8 discrete values each [index 0 - 7]

    // Constructors
    HashKey(uchar d1, uchar d2, uchar n1, uchar n2, uchar n3) : d1(d1), d2(d2), n1(n1), n2(n2), n3(n3) {}

    // Operators
    bool operator==(const HashKey &rhs) const;
    bool operator!=(const HashKey &rhs) const;
    friend std::ostream &operator<<(std::ostream &os, const HashKey &key);
};

struct HashKeyHasher {
    std::size_t operator()(const HashKey& k) const {
        std::hash<int> h;
        return h(k.d1 << 0 | k.d2 << 3 | k.n1 << 6 | k.n2 << 9 | k.n3 << 12);
    }
};

#endif //VSB_SEMESTRAL_PROJECT_HASHKEY_H
