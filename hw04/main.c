#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
constexpr int MAP_MAX = 200;
#endif /* __PROGTEST__ */

int maxOfTwo(int a, int b) {
    if (a > b){
        return a;
    } else {
        return b;
    }
}

void castleArea(int altitude[][MAP_MAX], int size, int area[][MAP_MAX]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int value = altitude[i][j];
            int maxUp = 0, maxDown = 0, maxLeft = 0, maxRight = 0;

            for (int k = i - 1; k >= 0 && altitude[k][j] < value; k--) maxUp++;
            for (int k = i + 1; k < size && altitude[k][j] < value; k++) maxDown++;
            for (int k = j - 1; k >= 0 && altitude[i][k] < value; k--) maxLeft++;
            for (int k = j + 1; k < size && altitude[i][k] < value; k++) maxRight++;

            int maxSegment = maxOfTwo(maxUp + maxDown + 1, maxLeft + maxRight + 1);

            int maxArea = 1; 
            for (int up = 0; up <= maxUp; up++) {
                for (int down = 0; down <= maxDown; down++) {
                    for (int left = 0; left <= maxLeft; left++) {
                        for (int right = 0; right <= maxRight; right++) {
                            bool isValid = true;
                            for (int r = i - up; r <= i + down && isValid; r++) {
                                for (int c = j - left; c <= j + right; c++) {
                                    if (altitude[r][c] >= value && (r != i || c != j)) {
                                        isValid = false;
                                        break;
                                    }
                                }
                            }
                            if (isValid) {
                                int areaSize = (up + down + 1) * (left + right + 1);
                                maxArea = (maxArea > areaSize) ? maxArea : areaSize;
                            }
                        }
                    }
                }
            }
       
            area[i][j] = maxOfTwo(maxSegment, maxArea);
        }
    }
}


#ifndef __PROGTEST__
bool identicalMap(const int a[][MAP_MAX], const int b[][MAP_MAX], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (a[i][j] != b[i][j]) {
                return false; 
            }
        }
    }
    return true; 
}

int main ( int argc, char * argv [] )
{
  static int result[MAP_MAX][MAP_MAX];

  static int alt0[MAP_MAX][MAP_MAX] =
  {
    { 1, 2 },
    { 3, 4 }
  };
  static int area0[MAP_MAX][MAP_MAX] =
  {
    { 1, 2 },
    { 2, 4 }
  };
  castleArea ( alt0, 2, result );
  assert ( identicalMap ( result, area0, 2 ) );
  static int alt1[MAP_MAX][MAP_MAX] =
  {
    { 2, 7, 1, 9 },
    { 3, 5, 0, 2 },
    { 1, 6, 3, 5 },
    { 1, 2, 2, 8 }
  };
  static int area1[MAP_MAX][MAP_MAX] =
  {
    { 1, 12, 2, 16 },
    { 4, 4, 1, 2 },
    { 1, 9, 4, 4 },
    { 1, 2, 1, 12 }
  };
  castleArea ( alt1, 4, result );
  assert ( identicalMap ( result, area1, 4 ) );
  static int alt2[MAP_MAX][MAP_MAX] =
  {
    { 1, 2, 3, 4 },
    { 2, 3, 4, 5 },
    { 3, 4, 5, 6 },
    { 4, 5, 6, 7 }
  };
  static int area2[MAP_MAX][MAP_MAX] =
  {
    { 1, 2, 3, 4 },
    { 2, 4, 6, 8 },
    { 3, 6, 9, 12 },
    { 4, 8, 12, 16 }
  };
  castleArea ( alt2, 4, result );
  assert ( identicalMap ( result, area2, 4 ) );
  static int alt3[MAP_MAX][MAP_MAX] =
  {
    { 7, 6, 5, 4 },
    { 6, 5, 4, 5 },
    { 5, 4, 5, 6 },
    { 4, 5, 6, 7 }
  };
  static int area3[MAP_MAX][MAP_MAX] =
  {
    { 12, 6, 2, 1 },
    { 6, 2, 1, 2 },
    { 2, 1, 2, 6 },
    { 1, 2, 6, 12 }
  };
  castleArea ( alt3, 4, result );
  assert ( identicalMap ( result, area3, 4 ) );
  static int alt4[MAP_MAX][MAP_MAX] =
  {
    { 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1 },
    { 1, 1, 2, 1, 1 },
    { 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1 }
  };
  static int area4[MAP_MAX][MAP_MAX] =
  {
    { 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1 },
    { 1, 1, 25, 1, 1 },
    { 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1 }
  };
  castleArea ( alt4, 5, result );
  assert ( identicalMap ( result, area4, 5 ) );
  return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */
