## Explaination

The code in this [JS file](convert-list-to-object.js) is a small snippet that can be useful when you need to transform an array into an oject. Enjoy! :tada:

### Example

```javascript
const foods = [{ food: 'bacon', id: '1234 '}, { food: 'eggs', id: '1345' }, { food: 'toast', id: '1456'}];
const clothes = [{ type: 'socks' }, { type: 'jacket' }, { type: 'shoes' }];

console.log(convertListToObject(foods, 'id'));
/*
 * {
 *   '1345': { food: 'eggs', id: '1345' },
 *   '1456': { food: 'toast', id: '1456' },
 *   '1234 ': { food: 'bacon', id: '1234 ' }
 * }
 */

console.log(convertListToObject(clothes));
/*
 * {
 *   '0': { type: 'socks' },
 *   '1': { type: 'jacket' },
 *   '2': { type: 'shoes' }
 * }
 */
```