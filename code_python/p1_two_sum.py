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



def twoSum(nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        key_value = {} # 数值作为key，索引作为value
        for i in range(len(nums)):
            #key_value[i] = nums[i]
            key_value[nums[i]] = i 
        # sorted(key_value.items(), key = lambda kv:(kv[1], kv[0]))

        res_id = []
        for i in range(len(nums)):
            res = target - nums[i]
            if res in key_value:
            # key_res = key_value.get(res, default=None)
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

