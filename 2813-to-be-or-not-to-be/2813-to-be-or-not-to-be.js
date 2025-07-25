/**
 * @param {string} val
 * @return {Object}
 */
/**
 * Creates an expectation object for testing values.
 *
 * @param {*} val The value to be tested.
 * @returns {object} An object with `toBe` and `notToBe` functions.
 */
var expect = function(val) {
    return {
        toBe: (val2) => {
            if (val !== val2){
                throw new Error("Not Equal");
            }else{
                return true;
            }
        },
        notToBe: (val2) => {
            if (val === val2){
                throw new Error("Equal");
            }
            else{
                return true;
            }
        }
    }
};


/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */