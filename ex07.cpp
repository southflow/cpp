#include <iostream>
using namespace std;

class HasPtr1 {
    public:
        HasPtr1(int *p, int i):ptr(p),val(i){}
        int *get_ptr() const {
            return ptr;
        }
        int get_int() const {
            return val;
        }
        void set_ptr(int *p) {
            ptr = p;
        }
        void set_int(int i) {
            val = i;
        }

        int get_ptr_val() const {
            return *ptr;
        }

        void set_ptr_val(int val) const {
            *ptr = val;
        }

    private:
        int *ptr;
        int val;
};

class U_Ptr {
    friend class HasPtr;
    int *ip;

    size_t use;

    U_Ptr(int *p): ip(p), use(1) {}
    ~U_Ptr() {delete ip;}

};

class HasPtr {
    public:
        HasPtr(int *p, int i):ptr(new U_Ptr(p)),val(i){}

        HasPtr(const HasPtr &orig):ptr(orig.ptr), val(orig.val) {
            ++ptr->use;
        }

        HasPtr& operator=(const HasPtr&);

        ~HasPtr() {
            cout << val << "ptr->use:" << ptr->use <<endl;
            --ptr->use;
            if(ptr->use == 0) {
                cout <<val<< "delete:" << ptr << endl;
                delete ptr;
            }
        }
        int *get_ptr() const {
            return ptr->ip;
        }
        int get_int() const {
            return val;
        }
        void set_ptr(int *p) {
            ptr->ip = p;
        }
        void set_int(int i) {
            val = i;
        }
        int get_ptr_val() const {
            return *ptr->ip;
        }
        void set_ptr_val(int val) const {
            *ptr->ip = val;
        }

    private:
        U_Ptr *ptr;
        int val;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    cout << val << "operator delete:" << ptr << endl;
    ++rhs.ptr->use;
    if(--ptr->use == 0) {
        
        delete ptr;
    }
    ptr = rhs.ptr;
    val = rhs.val;
    return *this;
}


class HasPtr2 {
    public:
        HasPtr2(const int &p, int i):ptr(new int(p)),val(i){}

        HasPtr2(const HasPtr2&orig):ptr(new int(*orig.ptr)),val(i){}
        HasPtr2& operator=(const HasPtr2&);
        ~HasPtr2() {
            delete ptr;
        }

        int *get_ptr() const {
            return ptr;
        }
        int get_int() const {
            return val;
        }
        void set_ptr(int *p) {
            ptr = p;
        }
        void set_int(int i) {
            val = i;
        }

        int get_ptr_val() const {
            return *ptr;
        }

        void set_ptr_val(int val) const {
            *ptr = val;
        }

    private:
        int *ptr;
        int val;
};

HasPtr2& HasPtr2::operator=(const HasPtr2& rhs) {
    *ptr = *rhs.ptr;
    val = rhs.val;
    return *this;
}

int main() {
    int obj = 1;
    HasPtr ptr1(new int(5), 42);
    HasPtr ptr2(ptr1);
    HasPtr ptr3(new int(3), 100);
    HasPtr ptr4(ptr3);
    ptr3 = ptr2;
    return 0;
}