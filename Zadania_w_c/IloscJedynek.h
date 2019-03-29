unsigned char Iloscjedynek(unsigned long int liczba){
    int jedynki=0;
    unsigned long int pomoc;
    while(liczba > 0) {
        pomoc = liczba << 1;
        if (pomoc < liczba) {
            jedynki++;
        }
        liczba <<= 1;
    }
    return (unsigned char) jedynki;
}