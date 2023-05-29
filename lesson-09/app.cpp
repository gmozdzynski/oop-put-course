#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class IntegerSequence {
public:
    virtual vector<int> Numbers() = 0;
};

class VectorSequence : public IntegerSequence {
private:
    vector<int> _numberSequence;

public:
    explicit VectorSequence(const vector<int> &numberSequence) : _numberSequence(numberSequence) {}

    vector<int> Numbers() override {
        return _numberSequence;
    }
};

class PositiveSequence : public IntegerSequence {
private:
    unique_ptr<IntegerSequence> numbers_;

public:
    explicit PositiveSequence(unique_ptr<IntegerSequence> numbers) : numbers_(move(numbers)) {}

    vector<int> Numbers() override {
        vector<int> content = numbers_->Numbers();
        content.erase(remove_if(content.begin(), content.end(), [](int num) {
            return num < 0;
        }), content.end());
        return content;
    }
};

class EvenSequence : public IntegerSequence {
private:
    unique_ptr<IntegerSequence> numbers_;

public:
    explicit EvenSequence(unique_ptr<IntegerSequence> numbers) : numbers_(move(numbers)) {}

    vector<int> Numbers() override {
        vector<int> content = numbers_->Numbers();
        content.erase(remove_if(content.begin(), content.end(), [](int num) {
            return num % 2 != 0;
        }), content.end());
        return content;
    }
};

class SortedSequence : public IntegerSequence {
private:
    unique_ptr<IntegerSequence> numbers_;

public:
    explicit SortedSequence(unique_ptr<IntegerSequence> numbers) : numbers_(move(numbers)) {}

    vector<int> Numbers() override {
        vector<int> content = numbers_->Numbers();
        sort(content.begin(), content.end());
        return content;
    }
};

int main() {
    vector<int> sequence = {5, -2, 10, 7, -3, 8, 1, 6, -4};
    unique_ptr<IntegerSequence> integerSequence = make_unique<VectorSequence>(sequence);


    integerSequence = make_unique<PositiveSequence>(move(integerSequence));
    integerSequence = make_unique<EvenSequence>(move(integerSequence));
    integerSequence = make_unique<SortedSequence>(move(integerSequence));

    vector<int> processedSequence = integerSequence->Numbers();

    cout << "Processed Sequence: ";
    for (int num : processedSequence) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
