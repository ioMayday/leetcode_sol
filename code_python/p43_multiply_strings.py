# -*- coding: utf-8 -*-
'''
功能：力扣题目43，字符串相乘
博客：Python世界：力扣题43大数相乘算法实践
地址：https://blog.csdn.net/qq_17256689/article/details/142068281
'''


# sol4：beat 34%
# 参考烧脑版的第二个思路进行python实现：先乘，再进位
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        # corner case
        if num1 == "0" or num2 == "0":
            return "0"
        elif num1 == "1":
            return num2
        elif num2 == "1":
            return num1

        # common case
        len1 = len(num1)
        len2 = len(num2)
        len_sum = len1 + len2

        # 从低位往高位相互进位，个、十、百、千、……
        n1_rev = num1[::-1]
        n2_rev = num2[::-1]
        multi_res_list = []

        # 整体乘完放1个数组
        num_rev_list = [0]*(len_sum)
        for i in range(len1):
            for j in range(len2):
                n1 = int(n1_rev[i])
                n2 = int(n2_rev[j])
                num_rev_list[i + j] += n1 * n2

        base = 10
        # 统一处理进制问题
        for i in range(len(num_rev_list) - 1):
            num_rev_list[i+1] += num_rev_list[i] // base
            num_rev_list[i] = num_rev_list[i] % base
        # 处理最高位的corner case
        # if (num_rev_list[len_sum - 1] == 0):

        multi_res_list = num_rev_list[::-1]
        non_zero_idx = 0
        for val in multi_res_list:
            if (val == 0):
                non_zero_idx += 1
            else:
                break
        multi_res_list = multi_res_list[non_zero_idx:]

        multi_res_str = "".join((str(i) for i in multi_res_list)) # 列表中的每个数字转字符串
        return multi_res_str


# 导入单元测试
import unittest

# function...

# 编写测试套
class TestSol(unittest.TestCase):
    def test_bound1(self):
        num1 = "2"
        num2 = "3"
        ret = "6"
        sol = Solution()
        self.assertEqual(sol.multiply(num1, num2), ret)

    def test_bound2(self):
        num1 = "37689269854"
        num2 = "12548698156"
        ret = "472951271117876189224"
        sol = Solution()
        self.assertEqual(sol.multiply(num1, num2), ret)

    def test_bound3(self):
        num1 = "1"
        num2 = "123456789"
        ret = "123456789"
        sol = Solution()
        self.assertEqual(sol.multiply(num1, num2), ret)

    def test_bound4(self):
        num1 = "123456789"
        num2 = "0"
        ret = "0"
        sol = Solution()
        self.assertEqual(sol.multiply(num1, num2), ret)

    def test_special1(self):
        num1 = "6"
        num2 = "501"
        ret = "3006"
        sol = Solution()
        self.assertEqual(sol.multiply(num1, num2), ret)

    def test_special2(self):
        num1 = "10"
        num2 = "10"
        ret = "100"
        sol = Solution()
        self.assertEqual(sol.multiply(num1, num2), ret)

    def test_special3(self):
        num1 = "99"
        num2 = "99"
        ret = "9801"
        sol = Solution()
        self.assertEqual(sol.multiply(num1, num2), ret)

    def test_common_case(self):
        num1 = "123"
        num2 = "456"
        ret = "56088"
        sol = Solution()
        self.assertEqual(sol.multiply(num1, num2), ret)


# 含测试套版本主调
if __name__ == '__main__':
    print('start!')
    unittest.main() # 启动单元测试
    print('done!')
