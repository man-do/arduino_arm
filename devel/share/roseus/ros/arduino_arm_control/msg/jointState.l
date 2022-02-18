;; Auto-generated. Do not edit!


(when (boundp 'arduino_arm_control::jointState)
  (if (not (find-package "ARDUINO_ARM_CONTROL"))
    (make-package "ARDUINO_ARM_CONTROL"))
  (shadow 'jointState (find-package "ARDUINO_ARM_CONTROL")))
(unless (find-package "ARDUINO_ARM_CONTROL::JOINTSTATE")
  (make-package "ARDUINO_ARM_CONTROL::JOINTSTATE"))

(in-package "ROS")
;;//! \htmlinclude jointState.msg.html


(defclass arduino_arm_control::jointState
  :super ros::object
  :slots (_angle _vel ))

(defmethod arduino_arm_control::jointState
  (:init
   (&key
    ((:angle __angle) (make-array 3 :initial-element 0.0 :element-type :float))
    ((:vel __vel) (make-array 3 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _angle __angle)
   (setq _vel __vel)
   self)
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:vel
   (&optional __vel)
   (if __vel (setq _vel __vel)) _vel)
  (:serialization-length
   ()
   (+
    ;; float32[3] _angle
    (* 4    3)
    ;; float32[3] _vel
    (* 4    3)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32[3] _angle
     (dotimes (i 3)
       (sys::poke (elt _angle i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[3] _vel
     (dotimes (i 3)
       (sys::poke (elt _vel i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32[3] _angle
   (dotimes (i (length _angle))
     (setf (elt _angle i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[3] _vel
   (dotimes (i (length _vel))
     (setf (elt _vel i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;;
   self)
  )

(setf (get arduino_arm_control::jointState :md5sum-) "83437f1ff145bcfd3c05b464bdbb43d7")
(setf (get arduino_arm_control::jointState :datatype-) "arduino_arm_control/jointState")
(setf (get arduino_arm_control::jointState :definition-)
      "#Header header 
float32[3] angle # degrees
float32[3] vel # deg/s
")



(provide :arduino_arm_control/jointState "83437f1ff145bcfd3c05b464bdbb43d7")


