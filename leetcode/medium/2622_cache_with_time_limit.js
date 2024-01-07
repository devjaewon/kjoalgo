/**
 * @description
 *  cache 객체에 대한 기본적인 구현을 객체지향적으로 할 수 있는지를 물어보는 문제로 보임.
 *  get, set, count 를 요구사항에 맞게 구현할 수 있는지
 * 
 *  특별한 건 없었음
 */
var TimeLimitedCache = function() {
    this.values = {};
    this.expires = {};
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    var isNotExpired = this.isNotExpired(key);

    this.values[key] = value;
    this.expires[key] = Date.now() + duration;

    return isNotExpired;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    if (!(key in this.values)) {
        return -1;
    }
    if (this.expires[key] <= Date.now()) {
        return -1;
    }

    return this.values[key];
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    var cache = this;
    var noExpired = Object.keys(this.expires).filter(function (key) {
        var isNotExpired = cache.isNotExpired(key);

        if (!isNotExpired) {
            cache.remove(key);
        }

        return isNotExpired;
    });

    return noExpired.length;
};

TimeLimitedCache.prototype.isNotExpired =  function(key) {
    return (key in this.expires) && this.expires[key] > Date.now();
}

TimeLimitedCache.prototype.remove =  function(key) {
    delete this.values[key];
    delete this.expires[key];
}
