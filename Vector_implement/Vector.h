class Vector {
    private:
        int size;
        int capacity;
        int * buffer;
    public:
        Vector();
        // Vector(int size_, int capacity_);
        int get_size() const;
        void erase(int);
        void clear();
        void insert(int, int);
        void get_data();
        void push_back(int);
        void pop_back();
        int operator[](int);
};