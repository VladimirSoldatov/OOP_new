#include <iostream>
class Array {
	friend std::ostream& operator<<(std::ostream&,
		const Array&);
	friend std::istream& operator>>(std::istream&, Array&);
public:
	explicit Array(int = 10);
	Array(const Array&);
	~Array();
	int length() const;
	const Array& operator=(const Array&);
	bool operator==(const Array&) const;
	bool operator!=(const Array& a) const {
		return !(*this == a);
	}
		int& operator[](int);
	int operator[](int) const;
private:
	int size;
	int* arr;
};