# Ensure the 'recordDate' column is a datetime type
weather['recordDate'] = pd.to_datetime(weather['recordDate'])