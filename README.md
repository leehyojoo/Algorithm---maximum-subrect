# Algorithm_Maximum_Subrect
sloving maximum subrect algorithm problem with 3 time complexity


위의 코드는 주어진 행렬에서 가장 큰 부분직사각형 합을 구하는 세 가지 알고리즘을 구현한 C 코드임. 각 알고리즘은 서로 다른 시간 복잡도를 가짐.

max_subrect_alg1: O(n^6) 알고리즘
이 알고리즘은 모든 가능한 부분직사각형을 탐색하여 합을 계산하고, 그 중 최댓값을 찾음. 이를 위해 네 개의 반복문을 중첩하여 사용함. 따라서 시간 복잡도는 O(n^6)임.

max_subrect_alg2: O(n^4) 알고리즘
이 알고리즘은 누적 행렬(cumulative matrix)을 활용하여 부분직사각형의 합을 효율적으로 계산함. 누적 행렬은 각 위치까지의 합을 저장하는 행렬로, 특정 부분직사각형의 합은 누적 행렬의 일부분을 이용하여 계산할 수 있음. 이를 위해 두 개의 반복문을 사용하여 누적 행렬을 계산한 후, 추가적인 두 개의 반복문을 사용하여 가능한 모든 부분직사각형의 합을 계산함. 따라서 시간 복잡도는 O(n^4)임.

max_subrect_alg3: O(n^3) 알고리즘
이 알고리즘은 행렬의 열을 고정한 상태에서 각 열에서 가능한 모든 부분직사각형의 합을 구하는 것을 목표로 함. 이를 위해 세 개의 반복문을 사용하여 열을 고정하고, 다른 두 개의 반복문을 사용하여 해당 열에서 가능한 모든 부분직사각형의 합을 계산함. 이 과정에서 동적 계획법(Dynamic Programming)을 사용하여 각 열에서 가능한 최대 합을 계산하고, 이를 전체 부분직사각형의 최대 합과 비교하여 업데이트함. 따라서 시간 복잡도는 O(n^3)임.

각 알고리즘은 주어진 행렬에서 가장 큰 부분직사각형 합을 구하는 목적은 동일하지만, 시간 복잡도가 서로 다름. max_subrect_alg3가 가장 효율적인 알고리즘이며, 큰 입력에 대해서도 비교적 빠른 실행 속도를 가짐.
