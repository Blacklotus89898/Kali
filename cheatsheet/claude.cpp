/*
 * ============================================================
 *   C++ CRASH COURSE & REVIEW
 *   Complete reference — compile with: g++ -std=c++17 -o course cpp_crash_course.cpp
 * ============================================================
 */

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <memory>
#include <stdexcept>
#include <functional>
#include <utility>
using namespace std;

// ─────────────────────────────────────────────────────────────
//  HELPERS
// ─────────────────────────────────────────────────────────────
void header(const string& title) {
    cout << "\n";
    cout << "══════════════════════════════════════════════════\n";
    cout << "  " << title << "\n";
    cout << "══════════════════════════════════════════════════\n";
}
void section(const string& title) {
    cout << "\n── " << title << " ──\n";
}


// ════════════════════════════════════════════════════════════
//  MODULE 1: BASICS & DATA TYPES
// ════════════════════════════════════════════════════════════
void module_basics() {
    header("MODULE 1: BASICS & DATA TYPES");

    section("Fundamental Types");
    int          age    = 25;           // 4 bytes, ±2 billion
    long long    big    = 9000000000LL; // 8 bytes, very large
    double       pi     = 3.14159265;   // 8 bytes, ~15 sig figs
    float        temp   = 98.6f;        // 4 bytes, ~7 sig figs
    char         grade  = 'A';          // 1 byte, single char
    bool         passed = true;         // true / false
    string       name   = "Alice";      // std::string
    unsigned int pos    = 42;           // non-negative only
    const double G      = 9.81;         // immutable constant

    cout << "int:        " << age    << "\n";
    cout << "long long:  " << big    << "\n";
    cout << "double:     " << pi     << "\n";
    cout << "float:      " << temp   << "\n";
    cout << "char:       " << grade  << "\n";
    cout << "bool:       " << boolalpha << passed << "\n";
    cout << "string:     " << name   << "\n";
    cout << "unsigned:   " << pos    << "\n";
    cout << "const:      " << G      << "\n";

    section("auto — type deduction (C++11)");
    auto x   = 42;       // deduced: int
    auto y   = 3.14;     // deduced: double
    auto str = string("hello");
    cout << "auto int: " << x << ", auto double: " << y << "\n";

    section("Type Casting");
    double ratio = (double)7 / 2;        // C-style cast
    int    trunc = static_cast<int>(pi); // C++ preferred
    cout << "7/2 as double: " << ratio << "\n";
    cout << "pi truncated:  " << trunc  << "\n";

    section("sizeof");
    cout << "sizeof(int)=" << sizeof(int)
         << "  sizeof(double)=" << sizeof(double)
         << "  sizeof(char)=" << sizeof(char) << "\n";

    /*
     * KEY TAKEAWAYS:
     *  - Prefer double over float for precision
     *  - Use const instead of #define for constants
     *  - auto avoids type mismatch bugs — use liberally
     *  - Use static_cast<> over C-style casts
     */
}


// ════════════════════════════════════════════════════════════
//  MODULE 2: CONTROL FLOW
// ════════════════════════════════════════════════════════════
void module_control_flow() {
    header("MODULE 2: CONTROL FLOW");

    section("if / else if / else");
    int score = 85;
    if (score >= 90)      cout << "Grade: A\n";
    else if (score >= 80) cout << "Grade: B\n";
    else if (score >= 70) cout << "Grade: C\n";
    else                  cout << "Grade: F\n";

    // Ternary operator
    string result = (score >= 60) ? "Pass" : "Fail";
    cout << "Result: " << result << "\n";

    section("switch");
    int day = 3;
    switch (day) {
        case 1: cout << "Monday\n";    break;
        case 2: cout << "Tuesday\n";   break;
        case 3: cout << "Wednesday\n"; break;
        case 4: cout << "Thursday\n";  break;
        case 5: cout << "Friday\n";    break;
        default: cout << "Weekend\n";  break;  // always include!
    }

    section("for loop");
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
    }
    cout << "\n";

    // Countdown
    for (int i = 10; i >= 0; i -= 3) {
        cout << i << " ";
    }
    cout << "\n";

    section("while loop");
    int n = 100;
    int steps = 0;
    while (n != 1) {
        n = (n % 2 == 0) ? n / 2 : 3 * n + 1; // Collatz
        steps++;
    }
    cout << "Collatz(100) steps: " << steps << "\n";

    section("do-while loop (runs at least once)");
    int count = 0;
    do {
        count++;
    } while (count < 5);
    cout << "count = " << count << "\n";

    section("Range-based for (C++11)");
    vector<string> fruits = {"apple", "banana", "cherry"};
    for (const string& f : fruits) {
        cout << f << " ";
    }
    cout << "\n";

    section("break and continue");
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) continue;  // skip even
        if (i > 7)      break;     // stop at 8
        cout << i << " ";          // prints: 1 3 5 7
    }
    cout << "\n";

    /*
     * KEY TAKEAWAYS:
     *  - Always use {} braces even for single-line bodies
     *  - switch needs break to prevent fall-through
     *  - Range-based for is cleanest for collections
     *  - Ternary: condition ? valueIfTrue : valueIfFalse
     */
}


// ════════════════════════════════════════════════════════════
//  MODULE 3: FUNCTIONS
// ════════════════════════════════════════════════════════════

// Function declaration (prototype) — allows calling before definition
int    add(int a, int b);
double power(double base, int exp);
void   printSeparator(char c = '-', int len = 40); // default params

// Overloaded functions — same name, different signatures
string describe(int n)    { return "int: "    + to_string(n); }
string describe(double d) { return "double: " + to_string(d); }
string describe(string s) { return "string: " + s; }

// Pass by VALUE — caller's copy unchanged
void doubleByVal(int x) { x *= 2; }

// Pass by REFERENCE — modifies caller's variable
void doubleByRef(int& x) { x *= 2; }

// Pass by CONST REFERENCE — no copy, no modification (best for large types)
void printString(const string& s) { cout << s << "\n"; }

// Returning multiple values via reference params
void minmax(const vector<int>& v, int& mn, int& mx) {
    mn = *min_element(v.begin(), v.end());
    mx = *max_element(v.begin(), v.end());
}

// Recursive functions
int  factorial(int n) { return (n <= 1) ? 1 : n * factorial(n - 1); }
int  fibonacci(int n) { return (n <= 1) ? n : fibonacci(n-1) + fibonacci(n-2); }

// Function returning function (C++11 std::function)
function<int(int)> makeMultiplier(int factor) {
    return [factor](int x) { return x * factor; };
}

void module_functions() {
    header("MODULE 3: FUNCTIONS");

    section("Basic calls & overloading");
    cout << "add(3,4) = " << add(3, 4) << "\n";
    cout << "power(2,10) = " << power(2, 10) << "\n";
    cout << describe(42) << "\n";
    cout << describe(3.14) << "\n";
    cout << describe("hello") << "\n";

    section("Pass by value vs reference");
    int a = 5;
    doubleByVal(a); cout << "After doubleByVal: " << a << "\n"; // 5
    doubleByRef(a); cout << "After doubleByRef: " << a << "\n"; // 10
    printString("const ref — no copy made");

    section("Default parameters");
    printSeparator();        // uses '-' and 40
    printSeparator('=', 20); // override both

    section("Return multiple values");
    vector<int> nums = {5, 2, 8, 1, 9, 3};
    int mn, mx;
    minmax(nums, mn, mx);
    cout << "min=" << mn << "  max=" << mx << "\n";

    section("Recursion");
    cout << "5! = " << factorial(5) << "\n";          // 120
    cout << "fib(10) = " << fibonacci(10) << "\n";    // 55

    section("Higher-order functions / lambdas");
    auto triple = makeMultiplier(3);
    cout << "triple(7) = " << triple(7) << "\n";      // 21

    // Lambda directly
    auto square = [](int x) -> int { return x * x; };
    cout << "square(9) = " << square(9) << "\n";      // 81

    // Lambda capturing
    int base = 100;
    auto addBase = [base](int x) { return base + x; };
    cout << "addBase(42) = " << addBase(42) << "\n";  // 142

    /*
     * KEY TAKEAWAYS:
     *  - Use const& for strings/vectors to avoid costly copies
     *  - Use & when you need to modify the caller's variable
     *  - Default params must be at the END of the parameter list
     *  - Lambdas: [capture](params) { body }
     *  - Every recursive function MUST have a base case!
     */
}

// Definitions for prototyped functions
int add(int a, int b) { return a + b; }
double power(double base, int exp) {
    double result = 1;
    for (int i = 0; i < exp; i++) result *= base;
    return result;
}
void printSeparator(char c, int len) {
    for (int i = 0; i < len; i++) cout << c;
    cout << "\n";
}


// ════════════════════════════════════════════════════════════
//  MODULE 4: ARRAYS, VECTORS & STRINGS
// ════════════════════════════════════════════════════════════
void module_arrays_strings() {
    header("MODULE 4: ARRAYS, VECTORS & STRINGS");

    section("C-style arrays (fixed size)");
    int scores[5] = {90, 85, 78, 92, 88};
    scores[0] = 95;
    int len = sizeof(scores) / sizeof(scores[0]); // only way to get size
    cout << "scores[0]=" << scores[0] << "  len=" << len << "\n";

    int matrix[2][3] = {{1,2,3},{4,5,6}};
    cout << "matrix[1][2]=" << matrix[1][2] << "\n";

    section("std::array (C++11) — safe, knows size");
    array<int, 5> arr = {10, 20, 30, 40, 50};
    cout << "size=" << arr.size() << "  front=" << arr.front()
         << "  back=" << arr.back() << "\n";
    cout << "at(2)=" << arr.at(2) << "\n";  // bounds-checked

    section("std::vector — dynamic array (preferred)");
    vector<int> v = {3, 1, 4, 1, 5, 9};
    v.push_back(2);             // add to end
    v.pop_back();               // remove from end
    v.insert(v.begin() + 2, 99); // insert at index 2
    v.erase(v.begin() + 2);     // erase at index 2

    cout << "size=" << v.size() << "  [0]=" << v[0] << "\n";
    cout << "elements: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    // Sort & search
    sort(v.begin(), v.end());
    cout << "sorted: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    bool found = binary_search(v.begin(), v.end(), 5);
    cout << "contains 5? " << boolalpha << found << "\n";

    section("2D vector");
    int rows = 3, cols = 4;
    vector<vector<int>> grid(rows, vector<int>(cols, 0));
    grid[1][2] = 42;
    cout << "grid[1][2]=" << grid[1][2] << "\n";

    section("std::string");
    string s = "Hello, World!";
    cout << "length=" << s.length() << "\n";
    cout << "substr(7,5)=" << s.substr(7, 5) << "\n";     // World

    size_t pos = s.find("World");
    if (pos != string::npos)
        cout << "'World' at index " << pos << "\n";

    s.replace(7, 5, "C++");
    cout << "after replace: " << s << "\n";

    // Convert
    string numStr = to_string(42);
    int    numInt = stoi("123");
    double numDbl = stod("3.14");
    cout << "to_string(42)='" << numStr << "'  stoi='123'=" << numInt
         << "  stod='3.14'=" << numDbl << "\n";

    // String stream — tokenizing
    section("stringstream — parsing");
    stringstream ss("10 20 30 40");
    int x;
    cout << "tokens: ";
    while (ss >> x) cout << x << " ";
    cout << "\n";

    /*
     * KEY TAKEAWAYS:
     *  - Prefer vector over C arrays (dynamic, knows size)
     *  - Prefer std::array over C arrays for fixed-size
     *  - Out-of-bounds on C arrays = undefined behavior (crash!)
     *  - string::npos is returned by find() when not found
     *  - reserve() upfront avoids reallocations: v.reserve(1000)
     */
}


// ════════════════════════════════════════════════════════════
//  MODULE 5: POINTERS & MEMORY
// ════════════════════════════════════════════════════════════
void module_pointers() {
    header("MODULE 5: POINTERS & MEMORY");

    section("Pointer basics");
    int  val = 42;
    int* ptr = &val;     // ptr holds ADDRESS of val

    cout << "val   = " << val  << "\n";   // 42
    cout << "&val  = " << &val << "\n";   // address (hex)
    cout << "ptr   = " << ptr  << "\n";   // same address
    cout << "*ptr  = " << *ptr << "\n";   // 42 (dereference)

    *ptr = 100;                            // modify through pointer
    cout << "val after *ptr=100: " << val << "\n";  // 100

    section("Null pointer");
    int* nullPtr = nullptr;  // C++11 — always initialize!
    if (nullPtr == nullptr)
        cout << "nullPtr is null (safe check)\n";
    // Never dereference null: *nullPtr would crash!

    section("Pointer arithmetic");
    int arr[] = {10, 20, 30, 40, 50};
    int* p = arr;               // points to arr[0]
    cout << "*(p+0)=" << *(p+0) << "  *(p+2)=" << *(p+2) << "\n";
    p++;
    cout << "after p++: *p=" << *p << "\n";  // 20

    section("Dynamic memory — new / delete");
    int* heap = new int(99);       // allocate on heap
    cout << "*heap = " << *heap << "\n";
    delete heap;                   // MUST free!
    heap = nullptr;                // good practice

    int* arr2 = new int[5]{1,2,3,4,5};
    cout << "arr2[2] = " << arr2[2] << "\n";
    delete[] arr2;                 // use delete[] for arrays!
    arr2 = nullptr;

    section("Smart pointers (C++11) — prefer over raw!");
    // unique_ptr — single owner, auto-deleted on scope exit
    unique_ptr<int> up = make_unique<int>(42);
    cout << "*unique_ptr = " << *up << "\n";
    // No delete needed — destructor handles it

    // shared_ptr — reference counted
    shared_ptr<int> sp1 = make_shared<int>(77);
    shared_ptr<int> sp2 = sp1;  // both own it
    cout << "*shared_ptr = " << *sp1
         << "  use_count=" << sp1.use_count() << "\n";  // 2

    // weak_ptr — non-owning observer
    weak_ptr<int> wp = sp1;
    if (auto locked = wp.lock()) {
        cout << "*weak_ptr (locked) = " << *locked << "\n";
    }

    /*
     * KEY TAKEAWAYS:
     *  - & = address-of   |   * = dereference
     *  - ALWAYS initialize pointers (to nullptr or an address)
     *  - new[] must be matched with delete[]
     *  - Prefer smart pointers — they eliminate memory leaks
     *  - unique_ptr = sole owner | shared_ptr = shared ownership
     *  - Never dereference a null or dangling pointer
     */
}


// ════════════════════════════════════════════════════════════
//  MODULE 6: OBJECT-ORIENTED PROGRAMMING
// ════════════════════════════════════════════════════════════

// ── 6a. Base class ──
class Shape {
protected:
    string color;
public:
    Shape(const string& c) : color(c) {}
    virtual ~Shape() {}                          // virtual destructor!

    virtual double area()      const = 0;        // pure virtual
    virtual string describe()  const = 0;

    string getColor() const { return color; }
};

// ── 6b. Derived classes ──
class Circle : public Shape {
    double radius;
public:
    Circle(double r, const string& c = "red")
        : Shape(c), radius(r) {}

    double area()     const override { return 3.14159 * radius * radius; }
    string describe() const override {
        return "Circle(r=" + to_string(radius) + ", color=" + color + ")";
    }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double w, double h, const string& c = "blue")
        : Shape(c), w(w), h(h) {}

    double area()     const override { return w * h; }
    string describe() const override {
        return "Rect(" + to_string(w) + "x" + to_string(h) + ", color=" + color + ")";
    }
};

// ── 6c. Operator overloading ──
class Vector2D {
public:
    double x, y;
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& o) const { return {x+o.x, y+o.y}; }
    Vector2D operator*(double scalar)     const { return {x*scalar, y*scalar}; }
    bool     operator==(const Vector2D& o) const { return x==o.x && y==o.y; }

    friend ostream& operator<<(ostream& os, const Vector2D& v) {
        return os << "(" << v.x << ", " << v.y << ")";
    }
};

// ── 6d. Template class ──
template<typename T>
class Stack {
    vector<T> data;
public:
    void push(const T& val) { data.push_back(val); }
    void pop()  { if (!data.empty()) data.pop_back(); }
    T&   top()  { return data.back(); }
    bool empty() const { return data.empty(); }
    size_t size() const { return data.size(); }
};

void module_oop() {
    header("MODULE 6: OBJECT-ORIENTED PROGRAMMING");

    section("Polymorphism via base class pointer");
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(5.0));
    shapes.push_back(make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(make_unique<Circle>(2.5, "green"));

    for (const auto& s : shapes) {
        cout << s->describe() << "  area=" << s->area() << "\n";
    }

    section("Operator overloading");
    Vector2D a(1, 2), b(3, 4);
    Vector2D c = a + b;
    Vector2D d = c * 2.0;
    cout << a << " + " << b << " = " << c << "\n";
    cout << c << " * 2 = " << d << "\n";
    cout << "a == a: " << boolalpha << (a == a) << "\n";

    section("Template class (generic Stack)");
    Stack<int> si;
    si.push(10); si.push(20); si.push(30);
    cout << "top=" << si.top() << "  size=" << si.size() << "\n";
    si.pop();
    cout << "after pop, top=" << si.top() << "\n";

    Stack<string> ss;
    ss.push("hello"); ss.push("world");
    cout << "string stack top=" << ss.top() << "\n";

    /*
     * KEY TAKEAWAYS:
     *  - virtual enables runtime polymorphism (dynamic dispatch)
     *  - Pure virtual (=0) makes class abstract
     *  - virtual destructor REQUIRED when deleting via base ptr
     *  - override keyword catches typos at compile time
     *  - friend allows non-member functions to access privates
     *  - Templates generate type-safe code for any type
     */
}


// ════════════════════════════════════════════════════════════
//  MODULE 7: STL CONTAINERS & ALGORITHMS
// ════════════════════════════════════════════════════════════
void module_stl() {
    header("MODULE 7: STL CONTAINERS & ALGORITHMS");

    section("map — sorted key-value O(log n)");
    map<string, int> wordCount;
    for (const string& w : {"the","cat","sat","on","the","mat","the"})
        wordCount[w]++;

    for (const auto& [word, cnt] : wordCount)  // structured binding C++17
        cout << word << ":" << cnt << "  ";
    cout << "\n";
    cout << "count('the')=" << wordCount.count("the") << "\n";

    section("unordered_map — hash table O(1) avg");
    unordered_map<char, int> freq;
    for (char c : string("mississippi")) freq[c]++;
    for (auto& [c, n] : freq) cout << c << ":" << n << "  ";
    cout << "\n";

    section("set — unique sorted elements");
    set<int> s = {5, 3, 8, 1, 3, 5, 9};  // duplicates removed
    cout << "set: ";
    for (int x : s) cout << x << " ";     // 1 3 5 8 9
    cout << "\n";
    s.insert(4);
    cout << "contains 8? " << s.count(8) << "\n";

    section("queue — FIFO");
    queue<string> q;
    q.push("first"); q.push("second"); q.push("third");
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";

    section("stack — LIFO");
    stack<int> stk;
    for (int i = 1; i <= 5; i++) stk.push(i);
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << "\n";

    section("priority_queue — max-heap");
    priority_queue<int> pq;
    for (int x : {3,1,4,1,5,9,2,6}) pq.push(x);
    cout << "top (max): " << pq.top() << "\n";  // 9

    // min-heap
    priority_queue<int, vector<int>, greater<int>> minPQ;
    for (int x : {3,1,4,1,5}) minPQ.push(x);
    cout << "min-heap top: " << minPQ.top() << "\n";  // 1

    section("STL Algorithms");
    vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    // sort
    sort(v.begin(), v.end());
    cout << "sorted: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    // reverse
    reverse(v.begin(), v.end());
    cout << "reversed: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    // sort back for binary_search
    sort(v.begin(), v.end());

    // binary_search (requires sorted)
    cout << "binary_search(7)=" << boolalpha << binary_search(v.begin(), v.end(), 7) << "\n";

    // accumulate, min/max
    int sum = accumulate(v.begin(), v.end(), 0);
    int mn  = *min_element(v.begin(), v.end());
    int mx  = *max_element(v.begin(), v.end());
    cout << "sum=" << sum << "  min=" << mn << "  max=" << mx << "\n";

    // count_if
    int evens = count_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
    cout << "even count=" << evens << "\n";

    // transform
    vector<int> doubled(v.size());
    transform(v.begin(), v.end(), doubled.begin(), [](int x){ return x*2; });
    cout << "doubled: ";
    for (int x : doubled) cout << x << " ";
    cout << "\n";

    // find_if
    auto it = find_if(v.begin(), v.end(), [](int x){ return x > 5; });
    if (it != v.end()) cout << "first > 5: " << *it << "\n";

    /*
     * KEY TAKEAWAYS:
     *  - map: sorted, O(log n) | unordered_map: O(1) avg, no order
     *  - set: unique sorted | unordered_set: unique, O(1) avg
     *  - Always check empty() before front()/top()/pop()
     *  - Algorithms need iterators: begin(), end()
     *  - binary_search requires pre-sorted data
     *  - Lambdas make algorithms powerful: [](T x){ return ...; }
     */
}


// ════════════════════════════════════════════════════════════
//  MODULE 8: MODERN C++ & ERROR HANDLING
// ════════════════════════════════════════════════════════════

// RAII — Resource Acquisition Is Initialization
class ManagedBuffer {
    int* data;
    size_t sz;
public:
    ManagedBuffer(size_t n) : data(new int[n]()), sz(n) {
        cout << "  [ManagedBuffer] allocated " << n << " ints\n";
    }
    ~ManagedBuffer() {
        delete[] data;
        cout << "  [ManagedBuffer] freed automatically\n";
    }
    int& operator[](size_t i) { return data[i]; }
    size_t size() const { return sz; }
};

// Exception-safe function
double safeDivide(double a, double b) {
    if (b == 0.0)
        throw invalid_argument("Division by zero!");
    return a / b;
}

// Custom exception
class NetworkError : public runtime_error {
    int code;
public:
    NetworkError(const string& msg, int c)
        : runtime_error(msg), code(c) {}
    int getCode() const { return code; }
};

void module_modern() {
    header("MODULE 8: MODERN C++ & ERROR HANDLING");

    section("Move semantics — avoid unnecessary copies");
    vector<int> src = {1, 2, 3, 4, 5};
    vector<int> dst = move(src);   // src is now empty!
    cout << "dst.size()=" << dst.size()
         << "  src.size()=" << src.size() << "\n";

    section("Structured bindings (C++17)");
    pair<string, int> p = {"Alice", 30};
    auto [name, age] = p;
    cout << name << " is " << age << "\n";

    map<string, double> scores = {{"math",95.5},{"english",88.0}};
    for (auto& [subject, score] : scores)
        cout << subject << "=" << score << "  ";
    cout << "\n";

    section("std::optional (C++17) — nullable values");
    // (showing manually since we may not want to include <optional>)
    // Simulated with pointer for compatibility:
    auto findValue = [](vector<int>& v, int target) -> int* {
        auto it = find(v.begin(), v.end(), target);
        return (it != v.end()) ? &*it : nullptr;
    };
    vector<int> nums = {1,2,3,4,5};
    int* found = findValue(nums, 3);
    cout << (found ? "found: " + to_string(*found) : "not found") << "\n";

    section("RAII — automatic resource management");
    {
        ManagedBuffer buf(10);
        buf[0] = 42;
        buf[9] = 99;
        cout << "  buf[0]=" << buf[0] << "  buf[9]=" << buf[9] << "\n";
    } // destructor called automatically here!

    section("Exception handling");
    // Basic
    try {
        double r = safeDivide(10, 0);
        cout << r;  // not reached
    } catch (const invalid_argument& e) {
        cout << "Caught: " << e.what() << "\n";
    }

    // Custom exception
    try {
        throw NetworkError("Connection refused", 503);
    } catch (const NetworkError& e) {
        cout << "NetworkError " << e.getCode() << ": " << e.what() << "\n";
    } catch (const exception& e) {
        cout << "Generic: " << e.what() << "\n";
    } catch (...) {
        cout << "Unknown exception\n";
    }

    section("Type aliases (using)");
    using IntVec    = vector<int>;
    using StringMap = map<string, string>;
    IntVec iv = {1, 2, 3};
    StringMap sm = {{"key","value"}};
    cout << "IntVec[0]=" << iv[0] << "  StringMap['key']=" << sm["key"] << "\n";

    section("constexpr — compile-time evaluation");
    constexpr int N = 10;
    constexpr int arr_size = N * N;
    cout << "constexpr arr_size=" << arr_size << "\n";

    /*
     * KEY TAKEAWAYS:
     *  - RAII: bind resource lifetime to object lifetime — no leaks
     *  - std::move transfers ownership — source becomes empty
     *  - Structured bindings [a, b] = pair/map entries — very clean
     *  - Exceptions propagate up the call stack until caught
     *  - catch(...) catches everything — always put it last
     *  - constexpr = evaluated at compile time = zero runtime cost
     */
}


// ════════════════════════════════════════════════════════════
//  MODULE 9: QUICK REFERENCE CHEATSHEET
// ════════════════════════════════════════════════════════════
void module_cheatsheet() {
    header("MODULE 9: COMPLEXITY & CHEATSHEET");

    cout << R"(
┌─────────────────────────────────────────────────────────┐
│              BIG-O COMPLEXITY REFERENCE                  │
├────────────────────────┬───────────┬───────────────────-─┤
│  Operation             │   Time    │   Notes              │
├────────────────────────┼───────────┼────────────────────-─┤
│  Array / vector access │   O(1)    │  arr[i]              │
│  vector push_back      │   O(1)*   │  amortized           │
│  vector insert/erase   │   O(n)    │  shifts elements     │
│  map insert/find       │   O(log n)│  tree-based          │
│  unordered_map         │   O(1)*   │  hash table          │
│  set insert/find       │   O(log n)│  balanced BST        │
│  binary_search         │   O(log n)│  requires sorted     │
│  std::sort             │  O(n logn)│  introsort           │
│  Linear search         │   O(n)    │  find()              │
│  Naive fibonacci       │   O(2^n)  │  use memoization!    │
└────────────────────────┴───────────┴──────────────────────┘

┌──────────────────────────────────────────────────────────┐
│              COMMON PITFALLS & FIXES                      │
├────────────────────────────────────────────────────────-─┤
│  PITFALL                      │  FIX                     │
├───────────────────────────────┼──────────────────────────┤
│  int arr[n]; // VLA           │  vector<int> v(n);       │
│  char* str;                   │  string str;             │
│  Raw new/delete               │  unique_ptr / vector     │
│  int* p; // uninitialized     │  int* p = nullptr;       │
│  delete ptr; ptr = ???        │  ptr = nullptr after del │
│  delete arr; // array         │  delete[] arr;           │
│  f(vector<T> v) // copy       │  f(const vector<T>& v)   │
│  Missing break in switch      │  Always add break;       │
│  No virtual destructor        │  Add virtual ~Base(){}   │
│  Comparing float with ==      │  abs(a-b) < 1e-9         │
└───────────────────────────────┴──────────────────────────┘

┌──────────────────────────────────────────────────────────┐
│              INCLUDE CHEATSHEET                           │
├──────────────────────────────────────────────────────────┤
│  #include <iostream>   → cout, cin, cerr, endl           │
│  #include <string>     → string, to_string, stoi, stod   │
│  #include <vector>     → vector<T>                       │
│  #include <array>      → array<T,N>                      │
│  #include <map>        → map<K,V>, multimap              │
│  #include <unordered_map> → unordered_map<K,V>           │
│  #include <set>        → set<T>, multiset                │
│  #include <queue>      → queue<T>, priority_queue<T>     │
│  #include <stack>      → stack<T>                        │
│  #include <algorithm>  → sort, find, binary_search...    │
│  #include <numeric>    → accumulate, iota, gcd, lcm      │
│  #include <memory>     → unique_ptr, shared_ptr          │
│  #include <functional> → function<>, greater<>           │
│  #include <sstream>    → stringstream                    │
│  #include <stdexcept>  → runtime_error, invalid_argument │
│  #include <cmath>      → sqrt, pow, abs, floor, ceil     │
│  #include <climits>    → INT_MAX, INT_MIN, LLONG_MAX     │
└──────────────────────────────────────────────────────────┘
)";
}


// ════════════════════════════════════════════════════════════
//  MAIN — run all modules
// ════════════════════════════════════════════════════════════
int main() {
    cout << R"(
 ██████╗ ██╗  ██╗
██╔════╝ ╚██╗██╔╝
██║       ╚███╔╝
██║       ██╔██╗
╚██████╗ ██╔╝ ██╗
 ╚═════╝ ╚═╝  ╚═╝   CRASH COURSE & REVIEW
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
  Compile: g++ -std=c++17 -Wall -o course cpp_crash_course.cpp
  Run:     ./course
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
)";

    module_basics();
    module_control_flow();
    module_functions();
    module_arrays_strings();
    module_pointers();
    module_oop();
    module_stl();
    module_modern();
    module_cheatsheet();

    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "  All modules complete. Happy coding!\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";

    return 0;
}