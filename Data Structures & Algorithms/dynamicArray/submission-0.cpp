class DynamicArray {
public:
    std::vector<int> vec;
  // Constructor to initialize the array with a given capacity
    DynamicArray(int initialCapacity) {
        if (initialCapacity > 0) {
            vec.reserve(initialCapacity);
        }
    }

    // Get the element at index i
    int get(int i) {
        return vec[i];
    }

    // Set the element at index i
    void set(int i, int n) {
        vec[i] = n;
    }

    // Add an element to the end of the array
    void pushback(int n) {
        vec.push_back(n);
    }

    // Remove and return the last element of the array
    int popback() {
        int value = vec.back();
        vec.pop_back();
        return value;
    }

    // Return the number of elements
    int getSize() const {
        return vec.size();
    }

    // Return the current capacity of the array
    int getCapacity() const {
        return vec.capacity();
    }
};

