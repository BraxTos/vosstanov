#include "List.h"
#include <cassert>
#include <iostream>

void test() {

    std::cout << "Test 1: Empty list\n";
    {
        List list;
        assert(list.isEmpty() == true);
        assert(list.size() == 0);
        assert(list.getHead() == nullptr);

        List result = list.removeConsecutiveDuplicates();
        assert(result.isEmpty() == true);
        assert(result.size() == 0);
    }
    std::cout << "  Passed ✓\n";

    std::cout << "Test 2: Single element\n";
    {
        List list;
        list.append(42);
        assert(list.isEmpty() == false);
        assert(list.size() == 1);
        assert(list.at(0) == 42);

        List result = list.removeConsecutiveDuplicates();
        assert(result.size() == 1);
        assert(result.at(0) == 42);
    }
    std::cout << "  Passed ✓\n";

    std::cout << "Test 3: All same elements\n";
    {
        List list;
        for (int i = 0; i < 5; i++) {
            list.append(5);
        }
        assert(list.size() == 5);

        List result = list.removeConsecutiveDuplicates();
        assert(result.size() == 1);
        assert(result.at(0) == 5);
    }
    std::cout << "  Passed ✓\n";

    std::cout << "Test 4: Example from the problem (1 1 2 3 3 3)\n";
    {
        List list;
        list.append(1);
        list.append(1);
        list.append(2);
        list.append(3);
        list.append(3);
        list.append(3);

        assert(list.size() == 6);

        List result = list.removeConsecutiveDuplicates();
        assert(result.size() == 3);
        assert(result.at(0) == 1);
        assert(result.at(1) == 2);
        assert(result.at(2) == 3);

        assert(list.size() == 6);
        assert(list.at(0) == 1);
        assert(list.at(1) == 1);
        assert(list.at(2) == 2);
        assert(list.at(3) == 3);
        assert(list.at(4) == 3);
        assert(list.at(5) == 3);
    }
    std::cout << "  Passed ✓\n";

    std::cout << "Test 5: No consecutive duplicates\n";
    {
        List list;
        list.append(1);
        list.append(2);
        list.append(3);
        list.append(4);
        list.append(5);

        assert(list.size() == 5);

        List result = list.removeConsecutiveDuplicates();
        assert(result.size() == 5);
        assert(result.at(0) == 1);
        assert(result.at(1) == 2);
        assert(result.at(2) == 3);
        assert(result.at(3) == 4);
        assert(result.at(4) == 5);

        assert(list.equals(result) == true);
    }
    std::cout << "  Passed ✓\n";

    std::cout << "Test 6: Complex case\n";
    {
        List list;
        list.append(5);
        list.append(5);
        list.append(1);
        list.append(2);
        list.append(2);
        list.append(3);
        list.append(3);
        list.append(3);
        list.append(4);
        list.append(4);
        list.append(5);
        list.append(5);
        list.append(5);
        list.append(1);

        assert(list.size() == 14);

        List result = list.removeConsecutiveDuplicates();
        assert(result.size() == 6);
        assert(result.at(0) == 5);
        assert(result.at(1) == 1);
        assert(result.at(2) == 2);
        assert(result.at(3) == 3);
        assert(result.at(4) == 4);
        assert(result.at(5) == 5);
        assert(result.size() == 7);
        assert(result.at(0) == 5);
        assert(result.at(1) == 1);
        assert(result.at(2) == 2);
        assert(result.at(3) == 3);
        assert(result.at(4) == 4);
        assert(result.at(5) == 5);
        assert(result.at(6) == 1);
    }
    std::cout << "  Passed ✓\n";

    std::cout << "Test 7: Copy constructor\n";
    {
        List original;
        original.append(1);
        original.append(2);
        original.append(3);

        List copy(original);
        assert(original.equals(copy) == true);

        copy.append(4);
        assert(original.size() == 3);
        assert(copy.size() == 4);

        assert(original.at(0) == 1);
        assert(original.at(1) == 2);
        assert(original.at(2) == 3);
    }
    std::cout << "  Passed ✓\n";

    std::cout << "Test 8: Assignment operator\n";
    {
        List list1;
        list1.append(10);
        list1.append(20);
        list1.append(30);

        List list2;
        list2.append(100);

        list2 = list1;
        assert(list1.equals(list2) == true);

        list2.append(40);
        assert(list1.size() == 3);
        assert(list2.size() == 4);

        list2 = list2;
        assert(list2.size() == 4);
    }
    std::cout << "  Passed ✓\n";

    std::cout << "Test 9: Prepending and appending\n";
    {
        List list;
        list.prepend(3);
        list.prepend(2);
        list.prepend(1);
        list.append(4);
        list.append(5);

        assert(list.size() == 5);
        assert(list.at(0) == 1);
        assert(list.at(1) == 2);
        assert(list.at(2) == 3);
        assert(list.at(3) == 4);
        assert(list.at(4) == 5);
    }
    std::cout << "  Passed ✓\n";

    std::cout << "Test 10: Edge cases for removeConsecutiveDuplicates\n";
    {
        List list1;
        list1.append(1);
        list1.append(1);
        list1.append(2);
        list1.append(3);

        List result1 = list1.removeConsecutiveDuplicates();
        assert(result1.size() == 3);
        assert(result1.at(0) == 1);
        assert(result1.at(1) == 2);
        assert(result1.at(2) == 3);

        List list2;
        list2.append(1);
        list2.append(2);
        list2.append(3);
        list2.append(3);

        List result2 = list2.removeConsecutiveDuplicates();
        assert(result2.size() == 3);
        assert(result2.at(0) == 1);
        assert(result2.at(1) == 2);
        assert(result2.at(2) == 3);
        List list3;
        list3.append(1);
        list3.append(1);
        list3.append(2);
        list3.append(2);
        list3.append(1);
        list3.append(1);

        List result3 = list3.removeConsecutiveDuplicates();
        assert(result3.size() == 3);
        assert(result3.at(0) == 1);
        assert(result3.at(1) == 2);
        assert(result3.at(2) == 1);
    }
    std::cout << "  Passed ✓\n";

    std::cout << "=====================\n";
    std::cout << "All tests passed! ✓\n";
    std::cout << "\n\nDemonstration of the example from the problem:\n";
    std::cout << "============================================\n";
}

int main() {
    test();
    return 0;
}