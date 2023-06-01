#ifndef MAGICAL_CONTAINER_H
#define MAGICAL_CONTAINER_H

#include <vector>
#include <set>

using namespace std;
namespace ariel {
    class MagicalContainer {
        private:
            vector<int> elements;
            vector<int> sortedElements;
            vector<int> primeElements;

            void insertSorted(int element) {
                auto iter = lower_bound(sortedElements.begin(), sortedElements.end(), element);
                sortedElements.insert(iter, element);
            }

            static bool isPrime(int num) {
                if (num <= 1) {
                    return false;
                }
                for (int i = 2; i * i <= num; ++i) {
                    if (num % i == 0) {
                        return false;
                    }
                }
                return true;
            }

            static void remove(vector<int>& vec, const int& element) {
                vec.erase(std::remove(vec.begin(), vec.end(), element), vec.end());
            }

        public:
            MagicalContainer();

            void addElement(int element);
            void removeElement(int element);
            int size() const;


            MagicalContainer(const MagicalContainer& other) = default;
            ~MagicalContainer() = default;
            MagicalContainer& operator=(const MagicalContainer& other);
            
            MagicalContainer& operator==(const MagicalContainer& other);
            MagicalContainer& operator!=(const MagicalContainer& other);
            MagicalContainer(MagicalContainer&& other) noexcept = default;
            MagicalContainer& operator=(MagicalContainer&&) noexcept = default;

            // Iterator classes
            class AscendingIterator;
            class SideCrossIterator;
            class PrimeIterator;

            //getters setters
            vector<int> getElements() const { return elements; }
            vector<int> getSortedElements() const { return sortedElements; }
            vector<int> getPrimeElements() const { return primeElements; }
    };

        // AscendingIterator
    class MagicalContainer::AscendingIterator {
        private:
            MagicalContainer& container;
            size_t current;

        public:
            AscendingIterator(MagicalContainer& container);

            AscendingIterator(const AscendingIterator& other) noexcept;
            ~AscendingIterator() = default;
            AscendingIterator& operator=(const AscendingIterator& other);
            AscendingIterator(AscendingIterator&& other) noexcept = default;
            AscendingIterator& operator=(AscendingIterator&&) noexcept;

            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            int operator*() const;
            AscendingIterator& operator++();
            AscendingIterator begin();
            AscendingIterator end();
    };

        // SideCrossIterator
    class MagicalContainer::SideCrossIterator {
        private:
            MagicalContainer& container;
            size_t forward;
            size_t backward;
            bool isForward;

        public:
            SideCrossIterator(MagicalContainer& container);

            SideCrossIterator(const SideCrossIterator& other) noexcept;
            ~SideCrossIterator() = default;
            SideCrossIterator& operator=(const SideCrossIterator& other);
            SideCrossIterator(SideCrossIterator&& other) noexcept = default;
            SideCrossIterator& operator=(SideCrossIterator&&) noexcept;

            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            int operator*() const;
            SideCrossIterator& operator++();
            SideCrossIterator begin();
            SideCrossIterator end();
    };

        // PrimeIterator
    class MagicalContainer::PrimeIterator {
        private:
            MagicalContainer& container;
            size_t current;

        public:
            PrimeIterator(MagicalContainer& container);

            PrimeIterator(const PrimeIterator& other) noexcept;
            ~PrimeIterator() = default;
            PrimeIterator& operator=(const PrimeIterator& other);
            PrimeIterator(PrimeIterator&& other) noexcept = default;
            PrimeIterator& operator=(PrimeIterator&&) noexcept;
            

            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            int operator*() const;
            PrimeIterator& operator++();
            PrimeIterator begin();
            PrimeIterator end();
    };
};


#endif  // MAGICAL_CONTAINER_H
