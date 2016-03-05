// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    Iterator *iterator;
    int peekedElement;
    bool hasPeeked;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    iterator = new Iterator(nums);
	    hasPeeked = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!hasPeeked) {
            peekedElement = iterator->next();
            hasPeeked = true;
        }
        return peekedElement;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (!hasPeeked) {
	        return iterator->next();
	    }
	    hasPeeked = false;
	    return peekedElement;
	}

	bool hasNext() const {
	    return hasPeeked || iterator->hasNext();
	}
};