/**
 * @description
 *  클로저 개념을 알고있는지 확인하는 문제로 보임
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let count = n;
    
    return function() {
        return count++; 
    };
};

/** 
* const counter = createCounter(10)
* counter() // 10
* counter() // 11
* counter() // 12
*/