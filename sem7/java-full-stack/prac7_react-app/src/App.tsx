import React, { useState, ChangeEvent } from "react";
import axios from "axios";

export default function App() {
  const [inputText, setInputText] = useState("");
  const [weatherData, setWeatherData] = useState<any>(null);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState("");

  // State for search functionality
  const [searchText, setSearchText] = useState("");
  const [indianLocations] = useState([
    "Mumbai",
    "Delhi",
    "Bengaluru",
    "Chennai",
    "Hyderabad",
    "Kolkata",
    "Ahmedabad",
    "Pune",
    "Jaipur",
    "Lucknow",
    "Surat",
    "Kanpur",
    "Nagpur",
    "Patna",
    "Indore",
    "Bhopal",
    "Vadodara",
    "Chandigarh",
    "Ranchi",
    "Guwahati",
    "Kochi",
    "Thiruvananthapuram",
    "Coimbatore",
    "Visakhapatnam",
    "Agra",
    "Varanasi",
    "Madurai",
    "Jodhpur",
    "Nashik",
    "Amritsar",
    "Raipur",
    "Dehradun",
    "Aurangabad",
    "Mysuru",
    "Jabalpur",
    "Vijayawada",
    "Udaipur",
    "Kozhikode",
    "Mangalore",
    "Rajkot",
    "Allahabad",
    "Gwalior",
    "Salem",
    "Srinagar",
    "Tiruchirappalli",
    "Noida",
    "Faridabad",
    "Ghaziabad",
    "Howrah",
    "Durgapur",
    "Bhubaneswar",
    "Dharamshala",
    "Shimla",
    "Haridwar",
    "Pondicherry",
    "Gandhinagar",
  ]);

  // Filter locations based on searchText
  const filteredLocations = indianLocations.filter((location) =>
    location.toLowerCase().includes(searchText.toLowerCase()),
  );

  // Handle location click (fetch weather details)
  const handleLocationClick = (location: string) => {
    setInputText(location);
    getLocationKey(location); // Fetch weather details for the clicked location
  };

  const API_KEY = import.meta.env.VITE_API_KEY as string;

  const locationKeyUrl = `http://dataservice.accuweather.com/locations/v1/cities/search?apikey=${API_KEY}&q=`;

  async function getLocationKey(location: string) {
    try {
      setLoading(true);
      setError(""); // Clear previous error if any
      const url = `${locationKeyUrl}${location}`;
      const res = await axios.get(url);

      if (res.data.length === 0) {
        throw new Error("Location not found");
      }

      const loc = res.data[0].Key;
      const weatherUrl = `http://dataservice.accuweather.com/currentconditions/v1/${loc}?apikey=${API_KEY}`;
      const weatherRes = await axios.get(weatherUrl);
      setWeatherData(weatherRes.data[0]);
    } catch (error: any) {
      setError(error.message || "Error fetching weather data");
    } finally {
      setLoading(false);
    }
  }

  const handleSearch = () => {
    if (inputText.trim()) {
      getLocationKey(inputText);
    }
  };

  return (
    <div className="flex w-screen min-h-screen">
      {/* Sidebar */}
      <div className="w-1/4 p-4 h-screen">
        <h2 className="text-lg font-bold mb-4">Popular Indian Locations</h2>

        {/* Search Bar */}
        <input
          type="text"
          placeholder="Search Indian location"
          className="w-full mb-4 p-2 border border-gray-300 rounded-lg"
          value={searchText}
          onChange={(e: ChangeEvent<HTMLInputElement>) =>
            setSearchText(e.target.value)
          }
        />

        {/* Scrollable Location List */}
        <div className="max-h-80 overflow-y-auto border border-gray-200 rounded-lg h-screen">
          <ul className="space-y-2">
            {filteredLocations.map((location, index) => (
              <li
                key={index}
                className="cursor-pointer p-2 hover:bg-sky-300 rounded-lg text-center"
                onClick={() => handleLocationClick(location)}
              >
                {location}
              </li>
            ))}
          </ul>
        </div>
      </div>

      {/* Main Content */}
      <div className="flex flex-col p-6">
        <p className="p-1 font-bold">Location Data</p>
        {/* Search Bar */}
        <div className="flex justify-center items-center mb-4">
          <input
            placeholder="Search Location"
            className="flex rounded-lg border-gray-300 px-4 py-2 text-black mr-2 bg-gray-100"
            value={inputText}
            onChange={(e: ChangeEvent<HTMLInputElement>) =>
              setInputText(e.target.value)
            }
          />
          <button
            className="bg-sky-500 text-white rounded-lg px-4 py-2 hover:bg-sky-600 transition-colors"
            onClick={handleSearch}
          >
            Search
          </button>
        </div>

        {/* Loading or Error Messages */}
        {loading && <p className="text-blue-600">Loading...</p>}
        {error && <p className="text-red-500">{error}</p>}

        {/* Weather Data */}
        {weatherData && (
          <div className="rounded-lg shadow-lg p-6 w-80">
            <div className="flex justify-center mb-4">
              <img
                src={`https://developer.accuweather.com/sites/default/files/${weatherData.WeatherIcon < 10 ? `0${weatherData.WeatherIcon}` : weatherData.WeatherIcon}-s.png`}
                alt="Weather Icon"
                className="w-fit h-fit"
              />
            </div>
            <div className="grid gap-4">
              <div>
                <span className="font-semibold">Temperature (Metric):</span>{" "}
                {weatherData.Temperature.Metric.Value}°C
              </div>
              <div>
                <span className="font-semibold">Temperature (Imperial):</span>{" "}
                {weatherData.Temperature.Imperial.Value}°F
              </div>
              <div>
                <span className="font-semibold">Weather:</span>{" "}
                {weatherData.WeatherText}
              </div>
              <div>
                <span className="font-semibold">Daytime:</span>{" "}
                {weatherData.IsDayTime ? "Yes" : "No"}
              </div>
              <div>
                <span className="font-semibold">Precipitation:</span>{" "}
                {weatherData.HasPrecipitation
                  ? weatherData.PrecipitationType || "Yes"
                  : "No"}
              </div>
              <div>
                <span className="font-semibold">Last Updated:</span>{" "}
                {new Date(
                  weatherData.LocalObservationDateTime,
                ).toLocaleString()}
              </div>
            </div>
          </div>
        )}
      </div>
    </div>
  );
}
