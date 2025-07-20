# test_sensor_manager.py
import pytest
from sensor_manager import SensorManager

def test_initialize():
    sm = SensorManager()
    assert sm.initialize() is True

def test_read_all_returns_data():
    sm = SensorManager()
    sm.initialize()
    data = sm.readAll()
    assert hasattr(data, 'timestamp')
    assert hasattr(data, 'ranges')
