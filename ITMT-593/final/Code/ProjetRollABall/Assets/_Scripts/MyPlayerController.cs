using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.IO.Ports;
using UnityEngine;
using UnityEngine.UI;

public class MyPlayerController : MonoBehaviour {

    public float speed;
    public Text countText;
    public Text winText;
    public Text scoreText;
    public string playerName;
    private Rigidbody rb;
    private int count;
    int seconds;
    SerialPort sp = new SerialPort("COM5", 250000);
    float xaxis;
    float yaxis;
    float timer = 0.0f;

    private string[] rcvdMessage;

    void Start()
    {
        rb = GetComponent<Rigidbody>();
        count = 0;
        SetCountText();
        winText.text = "";

        sp.Open();
        sp.ReadTimeout = 5;
    }

    void FixedUpdate()
    {

        try {
            rcvdMessage = sp.ReadLine().Split('/');
        }
        catch(System.Exception)
        {}
        
        xaxis = float.Parse(rcvdMessage[0]);
        yaxis = float.Parse(rcvdMessage[1]);


        //float moveHorizontal = Input.GetAxis("Horizontal");
        //float moveVertical = Input.GetAxis("Vertical");
        //print(moveVertical);
        //print(moveHorizontal);
        Vector3 movement = new Vector3(xaxis*0.01f, 0.0f, yaxis*0.01f);

        rb.AddForce(movement * speed);

        timer += Time.deltaTime;
        seconds = Convert.ToInt32(timer % 60);
        if (count < 12)
        {
            scoreText.text = Convert.ToString(seconds);
        }
    }

    void OnTriggerEnter(Collider other)
    {
        if(other.gameObject.CompareTag("Pickup"))
        {
            other.gameObject.SetActive(false);
            count++;
            SetCountText();
        }
        
    }

    void SetCountText()
    {
        countText.text = "Count : " + count.ToString();
        if (count>=12)
        {
            string winMessage = "You Win !!";
            print(winMessage);
            winText.text = "You Win !!";
            sp.WriteLine("Victory in " + Convert.ToString(seconds) + " seconds !!");
            writeStuffToFile(Convert.ToString(seconds));
        }
    }

    void writeStuffToFile(string message)
    {
        File.WriteAllText(Application.dataPath + "/stuff.txt", playerName + "'s score is " + message + "!!!");
    }
}