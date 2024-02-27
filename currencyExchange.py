import os
import requests
from dotenv import load_dotenv
load_dotenv()

def get_exchange_rate(api_key, from_currency, to_currency):
    url = f"https://v6.exchangerate-api.com/v6/{api_key}/pair/{from_currency}/{to_currency}"
    response = requests.get(url)
    if response.status_code == 200:
        data = response.json()
        return data.get('conversion_rate')
    else:
        print("Failed to retrieve data")
        return None

def convert_currency(amount, rate):
    return amount * rate

if __name__ == "__main__":
    api_key = os.environ.get("API_KEY")  # Replace with your actual API key
    from_currency = input("Enter the source currency code (e.g., USD): ")
    to_currency = input("Enter the target currency code (e.g., EUR): ")
    amount = float(input("Enter the amount to convert: "))
    
    rate = get_exchange_rate(api_key, from_currency, to_currency)
    if rate:
        converted_amount = convert_currency(amount, rate)
        print(f"{amount} {from_currency} is equal to {converted_amount:.2f} {to_currency}")
    else:
        print("Error converting currency.")
