#include "dictItem.h"

#include <sstream>

DictItem::DictItem(const std::string& key, const std::string& value)
    : mKey(rawQuote(key)), mValue(rawQuote(value)) {}

DictItem::DictItem(const std::string& key, DictItem dictValue)
    : mKey(rawQuote(key)), mValue(dictValue.str()) {}

DictItem::DictItem(const std::string& key, std::vector<DictItem>& values)
    : mKey(rawQuote(key)), mValue()
{
  std::stringstream dict;
  std::vector<DictItem>::iterator it;
  dict << "{";
  for (it = values.begin(); it != values.end(); it++) {
    dict << it->mKey << ": " << it->mValue;
    if (it < values.end() - 1) {
      dict << ", ";
    }
  }
  dict << "}";

  mValue = dict.str();
}

std::string DictItem::str()
{
  std::stringstream dict;
  dict << "{" << mKey << ": " << mValue << "}";

  return dict.str();
}

std::string DictItem::rawQuote(const std::string& value)
{
  std::stringstream quotedValue;
  quotedValue << "\"" << value << "\"";

  return quotedValue.str();
}