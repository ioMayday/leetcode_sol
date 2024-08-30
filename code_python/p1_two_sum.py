# 提交版本

# class Solution(object):
#     def twoSum(self, nums, target):
#         """
#         :type nums: List[int]
#         :type target: int
#         :rtype: List[int]
#         """
#         key_value = {} # 数值作为key，索引作为value
#         for i in range(len(nums)):
#             key_value[nums[i]] = i 

#         res_id = []
#         for i in range(len(nums)):
#             res = target - nums[i]
#             if res in key_value:
#                 kv = key_value[res]
#                 if kv != i:
#                     id_stop = key_value[res]
#                     res_id.append(i)
#                     res_id.append(id_stop)
#                     return res_id


# # Solution A：暴力求解，两遍for循环
# 时间复杂度：O(N^2)
# def twoSum(nums, target):
#         """
#         :type nums: List[int]
#         :type target: int
#         :rtype: List[int]
#         """
#         res_id = []
#         nums_len = len(nums)
#         for i in range(nums_len):
#               for j in range(nums_len):
#                     if i != j and nums[i] + nums[j] == target:
#                           res_id.append(i)
#                           res_id.append(j)
#                           return res_id


# Solution B：
# 1、建立一个字典
# 2、扫描一遍list，如果target-nums[i]结果在字典内，即返回
# 3、注意特例：减法结果为nums[i]时，无效
# 参考资料：
# https://blog.csdn.net/weixin_43557139/article/details/120626173
# https://www.runoob.com/python3/python-sort-dictionaries-by-key-or-value.html

# # solution1
# def twoSum(nums, target):
#         """
#         :type nums: List[int]
#         :type target: int
#         :rtype: List[int]
#         """
#         key_value = {} # 数值作为key，索引作为value
#         for i in range(len(nums)):
#             key_value[nums[i]] = i 

#         res_id = []
#         for i in range(len(nums)):
#             res = target - nums[i]
#             if res in key_value:
#                 kv = key_value[res]
#                 if kv != i:
#                     id_stop = key_value[res]
#                     res_id.append(i)
#                     res_id.append(id_stop)
#                     return res_id


def test(nums_sorted, target):
      res_sum = []
      idx_pair = []
      nums_len = len(nums_sorted)
      i = 0
      j = nums_len - 1
      while i != j :
            res = nums_sorted[i][0] + nums_sorted[j][0]
            res_sum.append(res)
            idx = []
            idx.append(i)
            idx.append(j)
            idx_pair.append(idx)
            if (res < target):
                  i += 1
            elif res > target:
                  j -= 1
            else:
                  break
      return res_sum, idx_pair


# Solution C：
# - 先升序排序，并保存原始index
# - 用双指针双向移动，找到匹配值
# - 时间复杂度：O(NlogN)
def twoSum(nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums_len = len(nums)
        nums_list = []
        idx = []
        val = []
        for i in range(nums_len):
              val.append(nums[i])
              idx.append(i)
        nums_list.append(val)
        nums_list.append(idx)

        nums_list = list(map(list, zip(*nums_list))) # 列表转置

        # print(nums_list)
        nums_sorted = sorted(nums_list, key=lambda x:x[0]) # 0按第0列排序
        # print(nums_sorted)

      #   # 测试双指针移动排序结果(两两之和，及对应idx)
      #   # 原理：a)排序后的最小和最大索引值结果，是序列中两数之和的中间界限。b)通过左右移动索引，即可调节目标两数和区间，实现O(N)便利，同时避免冗余查询。
      #   # half left
      #   sum_max = nums_sorted[nums_len - 1][0] + nums_sorted[nums_len - 2][0]
      #   res_sum_left, idx_pair_left = test(nums_sorted, sum_max)
      #   print(res_sum_left)
      #   print(idx_pair_left)

      #   # half right
      #   sum_min = nums_sorted[0][0] + nums_sorted[1][0]
      #   res_sum_right, idx_pair_right = test(nums_sorted, sum_min)
      #   print(res_sum_right)
      #   print(idx_pair_right)

        i = 0
        j = nums_len - 1
        while i != j :
              res = nums_sorted[i][0] + nums_sorted[j][0]
              if (res < target):
                    i += 1
              elif res > target:
                    j -= 1
              else:
                    break
        res_id = []
        res_id.append(nums_sorted[i][1])
        res_id.append(nums_sorted[j][1])
        return res_id


if __name__=="__main__":
    nums = [2,7,11,15]
    target = 9
    # nums = [3, 2, 4]
    # target = 6

    print(nums, target)
    res = twoSum(nums, target)
    print(res)

