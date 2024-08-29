# 提交版本

# 解题思路：
# 1、建立一个字典
# 2、扫描一遍list，如果target-nums[i]结果在字典内，即返回
# 3、注意特例：减法结果为nums[i]时，无效
# 参考资料：
# https://blog.csdn.net/weixin_43557139/article/details/120626173
# https://www.runoob.com/python3/python-sort-dictionaries-by-key-or-value.html

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



def twoSum(nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        key_value = {} # 数值作为key，索引作为value
        for i in range(len(nums)):
            key_value[nums[i]] = i 

        res_id = []
        for i in range(len(nums)):
            res = target - nums[i]
            if res in key_value:
                kv = key_value[res]
                if kv != i:
                    id_stop = key_value[res]
                    res_id.append(i)
                    res_id.append(id_stop)
                    return res_id

if __name__=="__main__":
    nums = [2,7,11,15]
    target = 9  
    # nums = [3, 2, 4]
    # target = 6
    res = twoSum(nums, target)
    print(res)

