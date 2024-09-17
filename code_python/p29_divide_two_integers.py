# -*- coding: utf-8 -*-
'''
功能：力扣题目29，两数相加
博客：Python世界：力扣29题两数相除算法实践
地址：https://blog.csdn.net/qq_17256689/article/details/142217434
'''

def get_sign(num: int) -> int:
    sign_num = 1
    if num < 0:
        sign_num = -1
    return sign_num


class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # 注意处理两者的输入边界，负号取绝对值存在溢出的问题。dividend
        abs_dvd = abs(dividend)
        abs_dvs = abs(divisor)
        sign_dvd = get_sign(dividend)
        sign_dvs = get_sign(divisor)

        # corner case
        if dividend == 0 or abs_dvd < abs_dvs:
            return 0
        if divisor == 1:
            return dividend
        if (divisor == -1):
            if (dividend != -2**31):
                return -dividend
            else:
                return 2**31-1

        # 原始方法，耗时过大
        res = 0
        while (abs_dvd >= abs_dvs):
            abs_dvd -= abs_dvs
            res += 1

        # 优化版本
        res = 0
        sum_rm = 0 # 记录被减去的总数
        while (abs_dvd >= abs_dvs + sum_rm): # 固定步长，移动sum_rm
            big_step = abs_dvs
            big_cnt = 1
            while (abs_dvd >= big_step + big_step + sum_rm):
                big_step += big_step # 移动步长
                big_cnt += big_cnt # 倍数步长
            sum_rm += big_step # 计入累积步长
            res += big_cnt # 计入累计步数

        if sign_dvd != sign_dvs:
            res *= -1
        return res

# 导入单元测试
import unittest

# 编写测试套
class TestSol(unittest.TestCase):
    def test_bound1(self):
        num1 = 7
        num2 = 1
        ret = 7
        sol = Solution()
        self.assertEqual(sol.divide(num1, num2), ret)

    def test_bound2(self):
        num1 = 7
        num2 = 7
        ret = 1
        sol = Solution()
        self.assertEqual(sol.divide(num1, num2), ret)

    def test_bound3(self):
        num1 = 2147483647
        num2 = -1
        ret = -2147483647
        sol = Solution()
        self.assertEqual(sol.divide(num1, num2), ret)

    def test_bound4(self):
        num1 = -2147483648
        num2 = -2147483648
        ret = 1
        sol = Solution()
        self.assertEqual(sol.divide(num1, num2), ret)

    def test_bound5(self):
        num1 = -2147483648
        num2 = -2
        ret = 1073741824
        sol = Solution()
        self.assertEqual(sol.divide(num1, num2), ret)

    def test_bound6(self):
        num1 = 2147483647
        num2 = 2
        ret = 1073741823
        sol = Solution()
        self.assertEqual(sol.divide(num1, num2), ret)

    def test_special1(self): # 负数极大值场景
        num1 = -2147483648
        num2 = -1
        ret = 2147483647
        sol = Solution()
        self.assertEqual(sol.divide(num1, num2), ret)

    def test_special2(self):
        num1 = -2147483648
        num2 = 1
        ret = -2147483648
        sol = Solution()
        self.assertEqual(sol.divide(num1, num2), ret)

    def test_common_case1(self):
        num1 = 7
        num2 = -3
        ret = -2
        sol = Solution()
        self.assertEqual(sol.divide(num1, num2), ret)

    def test_common_case2(self):
        num1 = 10
        num2 = -3
        ret = -3
        sol = Solution()
        self.assertEqual(sol.divide(num1, num2), ret)

    def test_common_case3(self):
        num1 = 10
        num2 = 3
        ret = 3
        sol = Solution()
        self.assertEqual(sol.divide(num1, num2), ret)


# 含测试套版本主调
if __name__ == '__main__':
    print('start!')
    unittest.main() # 启动单元测试
    print('done!')
