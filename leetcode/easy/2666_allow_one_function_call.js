/**
 * @description
 *  Closer 개념과 자바스크립트 function의 동작을 이해하고 있는지 확인하는 문제로 보임
 *  특별히 메모할 내용은 없음
 * 
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    var called = false;

    return function(...args){
        if (called) {
            return undefined;
        }

        called = true;
        return fn(...args);
    }
};
