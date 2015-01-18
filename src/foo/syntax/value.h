///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   value.h
//  Version     :   1.0
//  Author      :   Chenyizhan
//  Date        :   2014.04.30
//  Comment     :   值对象的实现
//
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include "base\log\log.h"
#include "json\json.h"


namespace FooScript{
    class FooCmdSystem;

    namespace Type{
        enum ValueType
        {
            nullValue = 0,
            intValue,     
            uintValue,    
            realValue,    
            stringValue,  
            booleanValue, 
            arrayValue,   
            objectValue,
            objectSPValue
        };
        class ValueObject : public Json::Value, public FooBase::Log::Pri::Printable{
        public:
            ValueObject() {}
            ValueObject(Int Value) : Json::Value(Value) {}
            ValueObject(UInt Value) : Json::Value(Value) {}
            ValueObject(Int64 Value) : Json::Value(Value) {}
            ValueObject(UInt64 Value) : Json::Value(Value) {}
            ValueObject(double Value) : Json::Value(Value) {}
            ValueObject(const char *Value) : Json::Value(Value) {}
            ValueObject(const char *beginValue, const char *endValue) : Json::Value(beginValue, endValue) {}
            ValueObject(const std::string &Value) : Json::Value(Value) {}
            ValueObject(bool Value) : Json::Value(Value) {}
            ValueObject(ValueType Type) : Json::Value(static_cast<Json::ValueType>(Type)) {}
            ValueObject(std::shared_ptr<ValueObject>& ValueSPtr) : 
                Json::Value(static_cast<std::shared_ptr<Json::Value>&>(
                    std::static_pointer_cast<Json::Value>(ValueSPtr))
                    ) {}

            virtual ~ValueObject() {}

            //ValueObject(ValueObject const&) = delete;
            //ValueObject& operator=(ValueObject const&) = delete;

            virtual const std::string ToString() const {
                return asString();
            }
            std::string asBuffer() const {
                std::string Buffer(size(), 0);
                for (auto i = 0u; i < size(); ++i) {
                    Buffer[i] = Json::Value::operator[](i).asInt();
                }
                return Buffer;
            }
            std::shared_ptr<ValueObject> asObjectSPtr() {
                // Json::Value is not a polymorphic type
                return std::static_pointer_cast<ValueObject>(Json::Value::asObjectSPtr());
            }
            std::shared_ptr<ValueObject> asObjectSPtr() const {
                // Json::Value is not a polymorphic type
                return std::static_pointer_cast<ValueObject>(Json::Value::asObjectSPtr());
            }
            virtual ValueObject& operator[](const std::string& Key) {
                Json::Value& v= Json::Value::operator[](Key);
                return *static_cast<ValueObject*>(&v);
            }
            virtual const ValueObject& operator[](const std::string& Key) const {
                const Json::Value& v = Json::Value::operator[](Key);
                return *static_cast<const ValueObject*>(&v);
            }
            //virtual ValueObject& operator[](const char* Key) {
            //    return *this;
            //}
            //virtual const ValueObject& operator[](const char* Key) const {
            //    return *this;
            //}
            virtual ValueObject& operator[](unsigned int Index) {
                Json::Value& v = Json::Value::operator[](Index);
                return *static_cast<ValueObject*>(&v);
            }
            virtual const ValueObject& operator[](unsigned int Index) const {
                const Json::Value& v = Json::Value::operator[](Index);
                return *static_cast<const ValueObject*>(&v);
            }
            ValueObject& operator=(const ValueObject& Right) {
                Json::Value::operator=(Right);
                return *this;
            }
            ValueObject get(const std::string &key,
                const ValueObject &defaultValue) const {
                const Json::Value& v = Json::Value::get(key, defaultValue);
                return *static_cast<const ValueObject*>(&v);
            }
        protected:
            const Json::Value&    GetJsonObject() const { return *this; }

        private:
        };
        typedef std::unique_ptr<ValueObject>    tValueUPtr;
        typedef std::shared_ptr<ValueObject>    tValueSPtr;
    }
}