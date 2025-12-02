
int makeNBOC(int num) {
    int test = 1;
    char *ptr = (char *)&test;

    if (*ptr == 1) {
        num = ((num & 0x000000FF) << 24) |
              ((num & 0x0000FF00) << 8) |
              ((num & 0x00FF0000) >> 8) |
              ((num & 0xFF000000) >> 24);
    }

    return num;
}