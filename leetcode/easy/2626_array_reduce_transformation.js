/**
 * @description
 *  reduce 함수의 동작방식을 이해하는지 확인하는 문제로 보임
 * 
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
  let accumulate = init;

  for (let i = 0; i < nums.length; i++) {
      accumulate = fn(accumulate, nums[i], i);
  }

  return accumulate;
};
