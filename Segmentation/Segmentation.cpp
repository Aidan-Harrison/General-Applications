#include <iostream>
#include <vector>

// Segmentation and pattern algorithms
void CornerSegmentation(std::vector<std::vector<int>> & arr, int count = 4, int corner = 1) {
    int xBound = arr[0].size()-1, yBound = arr.size()-1;
    int lXBound = xBound+1, lYBound = yBound+1;
    for(int i = 0; i < count; i++) {
        for(int j = 0; j <= xBound; j++) {
            arr[j][xBound] = 1;
            arr[yBound][j] = 1;
        }
        xBound = lXBound/2;
        yBound = lYBound/2;
        lXBound = xBound;
        lYBound = yBound;
    }
}

int main() {

    return 0;
}