# 두 수의 합
# 숫자들의 배열이 주어지고 표적 숫자가 주어졌다고 합시다.배열에 주어진 숫자들 중 두 개의 숫자를 더하면 표적 숫자가 되는데요,
# 이때 어떤 두 수를 더하면 표적숫자가 되는지 찾는 문제를 풀어 봅시다.
# 예를 들어서, [2, 8, 19, 37, 4, 5] 가 배열로 주어지고 12 가 표적으로 주어지면 8,4 를 찾아내시면 됩니다.
# 입력 배열에는 중복되는 수가 없습니다.
# 입력 배열에는 합해서 표적이 되는 어떤 두 수가 반드시 있습니다.
# 출력의 순서는 상관 없습니다.

import math

def twoSum(nums, target):
#     for n in nums:
#         if (target - n) in nums:
#             return n, (target-n)

    nums.sort() # 오름차순으로 정렬
    i = 0
    j = len(nums) - 1

    while i < j:
        sum = nums[i] + nums[j]
        if sum == target:
            return nums[i], nums[j]
        elif sum > target:
            j -= 1
        else:
            i += 1

def main():
    print(twoSum([2, 8, 19, 37, 4, 5], 12))

if __name__ == "__main__":
    main()