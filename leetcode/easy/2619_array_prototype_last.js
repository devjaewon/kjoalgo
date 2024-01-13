/**
 * @description
 *  prototype 객체 함수의 this가 현재 객체로 바인딩 되는 것을 확인하는 문제로 보임.
 */
/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
    if (this.length > 0) {
        return this[this.length - 1];
    }

    return -1;
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */
