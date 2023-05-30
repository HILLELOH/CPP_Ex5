#include "MagicalContainer.hpp"
//this is a cpp file that contain only empty functions, (the functions with non void return type return default value )
namespace ariel{
    // MagicalContainer
    MagicalContainer::MagicalContainer() {}

    void MagicalContainer::addElement(int element) {

    }

    void MagicalContainer::removeElement(int element) {
        
    }

    int MagicalContainer::size() const {
       return 0;
    }

    // AscendingIterator
    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container)
        : container(container), current(container.elements.begin()) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other)
        : container(other.container), current(other.current) {}

    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
        return *this;
    }


    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return false;
    }

    const int& MagicalContainer::AscendingIterator::operator*() const {
        return *current;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const{
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const{
        return *this;
    }

    // SideCrossIterator
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container)
        : container(container), forward(container.elements.begin()), backward(container.elements.end() - 1), isForward(true) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
        : container(other.container), forward(other.forward), backward(other.backward), isForward(other.isForward) {}

    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {   
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return false;
    }

    const int& MagicalContainer::SideCrossIterator::operator*() const {
        return *forward;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const{
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const{
        return *this;
    }

    // PrimeIterator
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container)
        : container(container), current(container.primeElements.begin()) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
        : container(other.container), current(other.current) {}

    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return false;

    }

    const int& MagicalContainer::PrimeIterator::operator*() const {
        return *current;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const{
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const{
        return *this;
    }

};

