function convertListToObject(list, keyBy) {
  return list.reduce((newObject, listItem, index) => {
    const key = keyBy ? listItem[keyBy] : index.toString();
    return {
      ...newObject,
      [key]: listItem
    };
  }, {});
}