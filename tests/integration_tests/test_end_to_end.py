# test_end_to_end.py
import pytest
from sensor_manager import SensorManager
from fusion_engine import FusionEngine
from decision_module import DecisionModule

def test_full_pipeline():
    sm = SensorManager(); sm.initialize()
    fe = FusionEngine()
    dm = DecisionModule()

    raw = sm.readAll()
    fused = fe.fuse(raw.ranges)
    decision = dm.evaluate(fused)
    assert isinstance(decision, bool)
