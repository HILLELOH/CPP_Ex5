#ifndef MAGICAL_CONTAINER_H
#define MAGICAL_CONTAINER_H

#include <vector>
#include <set>
namespace ariel {
    class MagicalContainer {
        private:
            std::vector<int> elements;
            std::multiset<int> sortedElements;
            std::set<int> primeElements;

        public:
            MagicalContainer();

            void addElement(int element);
            void removeElement(int element);
            int size() const;

            // Iterator classes
            class AscendingIterator;
            class SideCrossIterator;
            class PrimeIterator;
    };

        // AscendingIterator
    class MagicalContainer::AscendingIterator {
        private:
            const MagicalContainer& container;
            std::vector<int>::const_iterator current;

        public:
            AscendingIterator(const MagicalContainer& container);
            AscendingIterator(const AscendingIterator& other);
            ~AscendingIterator();

            AscendingIterator& operator=(const AscendingIterator& other);
            AscendingIterator(AscendingIterator&& other) noexcept;
            AscendingIterator& operator=(AscendingIterator&&) noexcept;


            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            const int& operator*() const;
            AscendingIterator& operator++();
            AscendingIterator begin() const;
            AscendingIterator end() const;
    };

        // SideCrossIterator
    class MagicalContainer::SideCrossIterator {
        private:
            const MagicalContainer& container;
            std::vector<int>::const_iterator forward;
            std::vector<int>::const_iterator backward;
            bool isForward;

        public:
            SideCrossIterator(const MagicalContainer& container);
            SideCrossIterator(const SideCrossIterator& other);
            ~SideCrossIterator();

            SideCrossIterator& operator=(const SideCrossIterator& other);
            SideCrossIterator(SideCrossIterator&& other) noexcept;
            SideCrossIterator& operator=(SideCrossIterator&&) noexcept;

            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            const int& operator*() const;
            SideCrossIterator& operator++();
            SideCrossIterator begin() const;
            SideCrossIterator end() const;
    };

        // PrimeIterator
    class MagicalContainer::PrimeIterator {
        private:
            const MagicalContainer& container;
            std::set<int>::const_iterator current;

        public:
            PrimeIterator(const MagicalContainer& container);
            PrimeIterator(const PrimeIterator& other);
            ~PrimeIterator();

            PrimeIterator& operator=(const PrimeIterator& other);
            PrimeIterator(PrimeIterator&& other) noexcept;
            PrimeIterator& operator=(PrimeIterator&&) noexcept;
            

            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            const int& operator*() const;
            PrimeIterator& operator++();
            PrimeIterator begin() const;
            PrimeIterator end() const;
    };
};


#endif  // MAGICAL_CONTAINER_H
