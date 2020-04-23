#include "Reflect.h"

namespace reflect {
//--------------------------------------------------------
// A type descriptor for 
//--------------------------------------------------------
#define DECLARATION_TYPE_DESCRIPTOR(T) \
struct TypeDescriptor_##T : TypeDescriptor { \
    TypeDescriptor_##T() : TypeDescriptor{#T, sizeof(T)} { } \
    virtual void dump(const void* obj, int /* unused */) const override { \
        std::cout << name << "{" << *(const T*) obj << "}"; \
    } \
}; \
template <> \
TypeDescriptor* getPrimitiveDescriptor<T>() { \
    static TypeDescriptor_##T typeDesc; \
    return &typeDesc; \
} \
template <> \
TypeDescriptor* getPrimitiveDescriptor<const T>() { \
    static TypeDescriptor_##T typeDesc; \
    return &typeDesc; \
}

typedef int8_t I8;
typedef uint8_t U8;
typedef int16_t I16;
typedef uint16_t U16;
typedef int32_t I32;
typedef uint32_t U32;
typedef int64_t I64;
typedef uint64_t U64;

DECLARATION_TYPE_DESCRIPTOR(char)
DECLARATION_TYPE_DESCRIPTOR(I8)
DECLARATION_TYPE_DESCRIPTOR(U8)
DECLARATION_TYPE_DESCRIPTOR(I16)
DECLARATION_TYPE_DESCRIPTOR(U16)
DECLARATION_TYPE_DESCRIPTOR(I32)
DECLARATION_TYPE_DESCRIPTOR(U32)
DECLARATION_TYPE_DESCRIPTOR(I64)
DECLARATION_TYPE_DESCRIPTOR(U64)

DECLARATION_TYPE_DESCRIPTOR(float)
DECLARATION_TYPE_DESCRIPTOR(double)
typedef long double ldouble;
DECLARATION_TYPE_DESCRIPTOR(ldouble)



//--------------------------------------------------------
// A type descriptor for std::string
//--------------------------------------------------------

struct TypeDescriptor_StdString : TypeDescriptor {
    TypeDescriptor_StdString() : TypeDescriptor{"std::string", sizeof(std::string)} {
    }
    virtual void dump(const void* obj, int /* unused */) const override {
        std::cout << "std::string{\"" << *(const std::string*) obj << "\"}";
    }
};

template <>
TypeDescriptor* getPrimitiveDescriptor<std::string>() {
    static TypeDescriptor_StdString typeDesc;
    return &typeDesc;
}

//--------------------------------------------------------
// A type descriptor for c string
//--------------------------------------------------------

struct TypeDescriptor_CString : TypeDescriptor {
    TypeDescriptor_CString() : TypeDescriptor{"cstring", sizeof(char*)} {
    }
    virtual void dump(const void* obj, int /* unused */) const override {
        if(*(const char**) obj)
            std::cout << "cstring{\"" << *(const char**) obj << "\"}";
        else 
            std::cout << "cstring{NULL}";
    }
};

template <>
TypeDescriptor* getPrimitiveDescriptor<char*>() {
    static TypeDescriptor_CString typeDesc;
    return &typeDesc;
}

template <>
TypeDescriptor* getPrimitiveDescriptor<const char*>() {
    static TypeDescriptor_CString typeDesc;
    return &typeDesc;
}



} // namespace reflect
