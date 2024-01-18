bool isValidInputFormat(int size, int hashFunction1, int hashFunction2 = 0) {
    if (size >= 0 && 
        ((hashFunction1 == 1 || hashFunction2 == 2) || 
         (hashFunction2 == 1 || hashFunction1 == 2)) &&
        (hashFunction2 == 0 || (hashFunction2 == 1 || hashFunction2 == 2))) {
        return true;
    } else {
        // Invalid input
        return false;
    }
}
