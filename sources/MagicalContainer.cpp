#include <stdexcept>
#include <iostream>
#include <stdexcept>
#include "MagicalContainer.hpp"
using namespace std;

namespace ariel{
    MagicalContainer::MagicalContainer() {}

    void MagicalContainer::addElement(int element) {
        elements.push_back(element);
        insertSorted(element);
        if(isPrime(element)){
            primeElements.push_back(element);
        }
    }

    void MagicalContainer::removeElement(int element) {
        //if element is not in the container throw run time error
        if(find(elements.begin(), elements.end(), element) == elements.end()){
            throw runtime_error("Element not in container");
        }
        remove(elements, element);
        remove(sortedElements, element);
        remove(primeElements, element);
    }

    int MagicalContainer::size() const {
       return elements.size();
    }

    MagicalContainer& MagicalContainer::operator=(const MagicalContainer& other){
        if(this != &other){
            elements = other.elements;
            sortedElements = other.sortedElements;
            primeElements = other.primeElements;
        }
        return *this;
    }

    // MagicalContainer& MagicalContainer::operator==(const MagicalContainer& other){
    //     // return elements == other.elements && sortedElements == other.sortedElements && primeElements == other.primeElements;
    // }

    // MagicalContainer& MagicalContainer::operator!=(const MagicalContainer& other){
    //     return !(*this == other);
    // }


    // AscendingIterator
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
        : container(container), current(0) {}


    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) noexcept
        : container(other.container), current(other.current) {}

    // MagicalContainer::AscendingIterator::~AscendingIterator() {}

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
        if(&container != &other.container){
            throw runtime_error("Cannot assign iterators of different containers");
        }
        if(this != &other){
            container = other.container;
            current = other.current;
        }
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return &container == &other.container && current == other.current;

    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return current > other.current;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return current < other.current;
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        return container.getSortedElements()[current];
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        if(current >= container.size()){
            throw runtime_error("Iterator out of bounds");
        }

        ++current;
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){
        current = 0;
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){
        current = static_cast<size_t>(container.size());
        return *this;
    }

    // SideCrossIterator
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)
        : container(container), forward(0), backward(static_cast<size_t>(container.size()-1)), isForward(true) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) noexcept
        : container(other.container), forward(other.forward), backward(other.backward), isForward(other.isForward) {}

    // MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
        if(&container != &other.container){
            throw runtime_error("Cannot assign iterators of different containers");
        }

        if(this != &other){
            container = other.container;
            forward = other.forward;
            backward = other.backward;
            isForward = other.isForward;
        }

        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return &container == &other.container && forward == other.forward 
        && backward == other.backward && isForward == other.isForward;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {   
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return forward > other.forward;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        if(isForward){
            return forward < other.forward;
        }

        return backward < other.backward;
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        if(isForward){
            return container.getSortedElements()[forward];
        }

        return container.getSortedElements()[backward];
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        if(forward >= container.size() || backward >= container.size()){
            throw runtime_error("Iterator out of bounds");
        }

        if (isForward) {
            ++forward;
            isForward = false;
        }

        else {
            --backward;
            isForward = true;
        }

        if(forward > backward){
            this->end();
            return *this;
        }

        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){
        forward = 0;
        backward = container.getElements().size() - 1;
        isForward = true;
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){
        forward = container.getElements().size();
        backward = 0;
        isForward = true;
        return *this;
    }

    // PrimeIterator
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
        : container(container), current(0) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) noexcept
        : container(other.container), current(other.current) {}

    // MagicalContainer::PrimeIterator::~PrimeIterator() {}

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
        if(&container != &other.container){
            throw runtime_error("Cannot assign iterators of different containers");
        }

        if(this != &other){
            container = other.container;
            current = other.current;
        }

        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return &container == &other.container && current == other.current;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return current > other.current;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return current < other.current;
    }

    int MagicalContainer::PrimeIterator::operator*() const {
        return container.getPrimeElements()[current];
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        if(current >= container.getPrimeElements().size()){
            throw runtime_error("Iterator out of bounds");
        }
        ++current;
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){
        current = 0;
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){
        current = container.getPrimeElements().size(); //last number
        return *this;
    }

};

