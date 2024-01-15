/**
 * @description
 *  함수 합성에 대해 묻는 문제
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    return function(x) {
        return functions.reduceRight((acc, fun) => fun(acc), x);
    }
};
