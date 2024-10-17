import React, { useState, ChangeEvent } from 'react';
import axios from 'axios';

export default function App() {
  const [inputText, setInputText] = useState('');
  const [tempMetric, setTempMetric] = useState(null);
  const [tempImperial, setTempImperial] = useState(null);
  const [weatherText, setWeatherText] = useState('');
  const [isDayTime, setIsDayTime] = useState(true);
  const [observationTime, setObservationTime] = useState('');
  const [hasPrecipitation, setHasPrecipitation] = useState(false);
  const [precipitationType, setPrecipitationType] = useState(null);
  const [weatherIcon, setWeatherIcon] = useState(null);

  const API_KEY = import.meta.env.VITE_API_KEY as string;

  const locationKeyUrl = `http://dataservice.accuweather.com/locations/v1/cities/search?apikey=${API_KEY}&q=`;

  async function getLocationKey(location: string) {
    try {
      const url = `${locationKeyUrl}${location}`;
      const res = await axios.get(url);
      const loc = res.data[0].Key;
      console.log(loc);
      const weatherUrl = `http://dataservice.accuweather.com/currentconditions/v1/${loc}?apikey=${API_KEY}`;
      const weatherRes = await axios.get(weatherUrl);
      const weatherData = weatherRes.data[0];

      setTempMetric(weatherData['Temperature']['Metric']['Value']);
      setTempImperial(weatherData['Temperature']['Imperial']['Value']);
      setWeatherText(weatherData['WeatherText']);
      setIsDayTime(weatherData['IsDayTime']);
      setObservationTime(weatherData['LocalObservationDateTime']);
      setHasPrecipitation(weatherData['HasPrecipitation']);
      setPrecipitationType(weatherData['PrecipitationType']);
      setWeatherIcon(weatherData['WeatherIcon']);
    } catch (error) {
      console.error('Error fetching weather data:', error);
    }
  }

  const handleSearch = () => {
    if (inputText) {
      getLocationKey(inputText);
    }
  };

  return (
    <div className='flex w-screen justify-center items-center'>
      <div className='flex-col justify-center items-center'>
        {/* Search bar */}
        <div className='flex justify-center items-center px-4 py-4'>
          <input
            placeholder='Search Location'
            className='flex rounded-lg border-gray-100 bg-gray-100 px-4 py-1 mx-2 text-black'
            value={inputText}
            onChange={(e: ChangeEvent<HTMLInputElement>) => setInputText(e.target.value)}
          />
          <button
            className='bg-sky-500 rounded-lg px-2 py-1'
            onClick={handleSearch}
          >
            Search
          </button>
        </div>

        {/* Weather Icon */}
        <div className='flex'>
          {weatherIcon && (
            <img
              src={`https://developer.accuweather.com/sites/default/files/${weatherIcon < 10 ? `0${weatherIcon}` : weatherIcon}-s.png`}
              alt='Weather Icon'
              className='flex justify-center items-center w-60 rounded-full ml-14'
            />
          )}
        </div>

        {/* Display */}
        <div className='flex-row border-slate-400 border-solid rounded-lg justify-center items-center px-3 py-2 ml-14'>
          <div>
            <span className='font-extrabold'>Temperature (Metric): </span>
            <span>{tempMetric ? `${tempMetric}°C` : 'N/A'}</span>
          </div>
          <div>
            <span className='font-extrabold'>Temperature (Imperial): </span>
            <span>{tempImperial ? `${tempImperial}°F` : 'N/A'}</span>
          </div>
          <div>
            <span className='font-extrabold'>Weather: </span>
            <span>{weatherText || 'N/A'}</span>
          </div>
          <div>
            <span className='font-extrabold'>Daytime: </span>
            <span>{isDayTime ? 'Yes' : 'No'}</span>
          </div>
          <div>
            <span className='font-extrabold'>Precipitation: </span>
            <span>{hasPrecipitation ? precipitationType || 'Yes' : 'No'}</span>
          </div>
          <div>
            <span className='font-extrabold'>Last Updated: </span>
            <span>{observationTime || 'N/A'}</span>
          </div>
        </div>
      </div>
    </div>
  );
}
