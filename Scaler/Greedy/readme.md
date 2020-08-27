# Description
This API is created for the **Midmile Location Data Visualization Tool**

The points are divided into 4 sections ie: Moving, Idle, Halt, Non Reliable.

**Moving**: When speed > 0

**Non Reliable**: When speed is not available in the data

**Idle**: If distance travelled between 2 points is less than 15 meters and speed is less than 2.5kmph

**Halt**: Once an idle is detected, if the duration carries on for more than 10mins the item is classified as a halt.

### Specifications
Environment: **Dev**

Method **GET**

HeaderKey **Authorization**

Header Value **Key**

### CURL Example
```sh
curl -X GET \
'http://mtsapi.delhivery.com/v2/midmile/locations?device_id=NL01AB4771&stis=1556956629000&etis=1557004092000&application=midmile&address=true' \
-H 'Authorization: Bearer Token' \
-H 'Content-Type: application/json'
```

### Endpoints

|    Env  | Endpoint |
| ------- | -------- |
|   Prod	| http://mtsapi.delhivery.com/v2/midmile/locations | 
| Staging | http://mts-staging.delhivery.com/v2/midmile/locations |

### Attributes
##### Mandatory Query Parameters
|   Attribute   | Type | Descrition | 
| ------------ | --------- | ----------- | 
|  application   |   String     | Name of application (midmile, LastMile, odx-fm)
|     device_id     |   String	   | Device ID
|     etis     |   Int	   | End timestamp in epoch milliseconds
| split_on_vendor  |   String	   | Splits the response data based on vendor (1 if needed)
| stis |   String     | Start timestamp in epoch milliseconds

#### Optional Query Parameters
|   Attribute   | Type | Descrition | 
| ------------ | --------- | ----------- | 
|  address   |   String     | true
|     trace_quality_only     |   String	   | true - If this key is passed with value true, only the trace quality will be returned
|     scroll_id     |   String	   | Base64 string will be returned if there is more data to be returned for a particular device_id. This string has to be passed in the next API call to get the rest of the data from that device_id - application combination till the scroll_id is nil / not found.

## URL
**PROD:**

    https://mtsapi.delhivery.com/v2/midmile/locations

**Staging:**

    https://mts-staging.delhivery.com/v2/midmile/locations

**Dev:** 

    https://mts-dev.delhivery.com/v2/midmile/locations



### Reference Output
#### StatusCode: 200	
```json
{
"data": [
{
  "vehile_number": "NL01AC3240",
  "vendor": "lynkit",
  "vendor_unique_id": "lynkit-861230045850824-L19A0137",
  "stis": 1584943018000,
  "etis": 1584951221000,
  "trace_quality": {
    "total_trace_points_count": 277,
    "tis_median_seconds": 30,
    "kinesis_arrival_to_tis_median_seconds": 42,
    "tis_median_capped": false,
    "expected_points_count": 7413,
    "percentage_of_trace_coverage": 3.74,
    "no_data_for_15mins_instances": 0,
    "no_distance_for_5km_instances": 0,
    "distance_rs_v1": 0.14,
    "invalid_gps_packets_count": 2,
    "invalid_gps_packets_percentage": 0.72
  },
  "statistics": {
    "average_moving_speed_kmph": 0.02,
    "distance_travelled_kms": 0.14,
    "total_count_halt_instances": 2,
    "total_time_seconds": 8203,
    "total_moving_time_seconds": 176,
    "total_halt_time_seconds": 8027
  },
  "data": [
    {
      "tis": 1584943048000,
      "lat": 19.240512,
      "lon": 73.028736,
      "spd_kmph": 0,
      "type": "Moving",
      "duration_seconds": 30,
      "distance_km": 0,
      "lock_device_id": "L19A0137",
      "distance_km_sum": 0,
      "gps_validity": "valid",
      "vendor_device_id": "861230045850824"
    },
    {
      "tis": 1584943077000,
      "lat": 19.240512,
      "lon": 73.028736,
      "spd_kmph": 0,
      "type": "Moving",
      "duration_seconds": 29,
      "distance_km": 0,
      "lock_device_id": "L19A0137",
      "distance_km_sum": 0,
      "gps_validity": "valid",
      "vendor_device_id": "861230045850824"
    },
    {
      "tis": 1584943107000,
      "lat": 19.240512,
      "lon": 73.028736,
      "spd_kmph": 0,
      "type": "Moving",
      "duration_seconds": 30,
      "distance_km": 0,
      "lock_device_id": "L19A0137",
      "distance_km_sum": 0,
      "gps_validity": "valid",
      "vendor_device_id": "861230045850824"
    },
    {
      "tis": 1584950489000,
      "stis": 1584943107000,
      "lat": 19.240512,
      "lon": 73.028736,
      "spd_kmph": 0,
      "type": "Halt",
      "duration_seconds": 7382,
      "distance_km": 0,
      "address": "Bhivandi, Thane, Maharashtra, 421302, India",
      "lock_device_id": "L19A0137",
      "distance_km_sum": 0,
      "gps_validity": "valid",
      "vendor_device_id": "861230045850824"
      }
    ]
    }
  ]
}
```

#### Status Code: 404 
```json
{
"message": "Exception: No Data found for DeviceID:HR55AG8378 and Application:midmile"
}
```

### Lambda Information

*Environment Variables Using in the Lambda*

| Env variable | Description | 
| ------------ | ----------- | 
| env          | Environment has to be set to prod / staging or dev
| v_level      | Logging level to be printed 0,1,2,3
| account      | Optional Variable, to be used when the lambda would be running on Prod AWS Account, if account is not supplied, by default the lambda will take delhivery-odx as the account

### API Gateway Configuration

Request Mapping

```sh
{
  "Authorization": "$input.params('Authorization')",
  "queryParams": {
    #foreach($param in $input.params().querystring.keySet())
    "$param": "$util.escapeJavaScript($input.params().querystring.get($param))" #if($foreach.hasNext),#end

    #end
  },
  "pathParams": {
    #foreach($param in $input.params().path.keySet())
    "$param": "$util.escapeJavaScript($input.params().path.get($param))" #if($foreach.hasNext),#end

    #end
  }
}
```

Response Mapping
```sh
$util.parseJson($input.json('$.errorMessage'))
```
