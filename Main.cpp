#include <vector>
#include "Reflect.h"
struct Obj {
    char c;
    unsigned char uc;
    short s;
    unsigned short us;
    int d;
    unsigned int u;
    long l;
    unsigned long ul;
    float f;
    double lf;
    char* str;
    const char* cstr;
    size_t size;
    char buff[100];
    REFLECT() 

};
struct Node {
    std::string key;
    int value;
    Obj obj;
    std::vector<Node> children;

    REFLECT()       // Enable reflection for this type
};
char* g_str="abcdefg";
int main() {
    // Create an object of type Node
    Node node = {"apple", 3, {'A', 213, 21648, 65535, -987, 98767, -987654567, 23423535445, 0.317f, -0.65f, g_str, g_str, (size_t)-1,"sdklfjsdlk" }, {{"banana", 7, {}, {}}, {"cherry", 11, {}, {}}}};

    // Find Node's type descriptor
    reflect::TypeDescriptor* typeDesc = reflect::TypeResolver<Node>::get();

    // Dump a description of the Node object to the console
    typeDesc->dump(&node);

    // Obj obj= {'A', 213, 21648, 65535, -987, 98767, -987654567, 23423535445, 0.317f, -0.65f, g_str, g_str, (size_t)-1 };

    // typeDesc = reflect::TypeResolver<Obj>::get();

    // // Dump a description of the Node object to the console
    // typeDesc->dump(&obj);
    return 0;
}

// Define Node's type descriptor
REFLECT_STRUCT_BEGIN(Node)
REFLECT_STRUCT_MEMBER(key)
REFLECT_STRUCT_MEMBER(value)
REFLECT_STRUCT_MEMBER(obj)
REFLECT_STRUCT_MEMBER(children)
REFLECT_STRUCT_END()

REFLECT_STRUCT_BEGIN(Obj)
REFLECT_STRUCT_MEMBER(c)
REFLECT_STRUCT_MEMBER(uc)
REFLECT_STRUCT_MEMBER(s)
REFLECT_STRUCT_MEMBER(us)
REFLECT_STRUCT_MEMBER(d)
REFLECT_STRUCT_MEMBER(u)
REFLECT_STRUCT_MEMBER(l)
REFLECT_STRUCT_MEMBER(ul)
REFLECT_STRUCT_MEMBER(f)
REFLECT_STRUCT_MEMBER(lf)
REFLECT_STRUCT_MEMBER(str)
REFLECT_STRUCT_MEMBER(cstr)
REFLECT_STRUCT_MEMBER(size)
REFLECT_STRUCT_MEMBER(buff)
REFLECT_STRUCT_END()
